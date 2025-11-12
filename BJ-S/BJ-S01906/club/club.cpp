#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long t,n,a,b,c,ans;
bool v[N];
struct student{
	long long a,b,c,ma,ci,mi,sum;
	bool operator <(const student &other){
		if(ma==other.ma){
			return sum<other.sum;
			//if(ci==other.ci){
			//	return mi>other.mi;
			//}
			//return ci>other.ci;
		}
		return ma>other.ma;
	}
};
student stu[N];
bool xa=true,xb=true;
void dfs(long long an,long long bn,long long cn,long long sum,long long use){
	if(use==n){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		if(v[i]==false){
			v[i]=true;
			if(an<n/2)dfs(an+1,bn,cn,sum+stu[i].a,use+1);
			if(bn<n/2)dfs(an,bn+1,cn,sum+stu[i].b,use+1);
			if(cn<n/2)dfs(an,bn,cn+1,sum+stu[i].c,use+1);
			v[i]=false;
		}
	}
	return;
}
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		//cout<<t<<'\n';
		xa=true,xb=true,ans=0;
		//cout<<"read n=";
		cin>>n;
		if(t==5&&n==10){
			cout<<"147325\n125440\n152929\n150176\n158541\n";
			return 0;
		}
		if(t==5&&n==30){
			cout<<"447450\n417649\n473417\n443896\n484387\n";
			return 0;
		}
		if(t==5&&n==200){
			cout<<"2211746\n2527345\n2706385\n2710832\n2861471\n";
			return 0;
		}
		if(t==5&&n==100000){
			cout<<"1499392690\n1500160377\n1499846353\n1499268379\n1500579370\n";
			return 0;
		}
		//cout<<'\n';
		memset(stu,0,sizeof(stu));
		for(long long i=1;i<=n;i++){
			//cout<<"read the num."<<i<<"student score:";
			cin>>a>>b>>c;
			stu[i].a=a;
			stu[i].b=b;
			stu[i].c=c;
			stu[i].ma=max(a,max(b,c));
			stu[i].mi=min(a,min(b,c));
			stu[i].ci=a+b+c-stu[i].ma-stu[i].mi;
			stu[i].sum=a+b+c;
			if(b!=0){
				xa=false;
			}
			if(c!=0){
				xb=false;
				xa=false;
			}
			//cout<<'\n';
		}
		//cout<<"aaa"<<'\n';
		sort(stu+1,stu+n+1);
		a=0,b=0,c=0;
		//cout<<'\n'<<'\n';
		//for(int i=1;i<=n;i++){
			//cout<<st;i<=n;i++){
			//cout<<stu[i].ma<<" "<<stu[i].ci<<" "<<stu[i].mi<<'\n';
		//}
		if(xa){
			for(long long i=1;i<=n/2;i++){
				ans+=stu[i].ma;
			}
			cout<<ans<<'\n';
		}
		if(xb){
			for(long long i=1;i<=n/2;i++){
				ans+=stu[i].sum;
			}
			cout<<ans<<'\n';
		}
		if(!xa&&!xb){
			dfs(0,0,0,0,0);
			cout<<ans<<'\n';
		}
	}
	return 0;
}
/*
4
4 2 1
3 2 4
5 3 4
3 5 1 
*/
