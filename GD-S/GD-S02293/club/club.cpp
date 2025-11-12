#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a,b,c,x,y,z;
int n,ans=0;
int n1=0,n2=0,n3=0;
bool teshu=true;
bool teshu2=true;
struct student{
	int fir,sec,thi;
	bool fla=false;
}q[N];

bool cmp1(student m,student v){
	return m.fir>v.fir;
}
bool cmp2(student m,student v){
	return m.sec>v.sec;
}
bool cmp3(student m,student v){
	return m.thi>v.thi;
}

void solve1(int p){ 
	if(p==x && (n1+1)<=(n/2)){
		ans+=p;
		sort(q+1,q+1+n,cmp1);
		n1++;
		q[a].fla=true;
	}
	if(p==y && (n2+1)<=(n/2)){
		ans+=p;
		sort(q+1,q+1+n,cmp2);
		n2++;
		q[b].fla=true;
	}
	if(p==z && (n3+1)<=(n/2)){
		ans+=p;
		sort(q+1,q+1+n,cmp3);
		n3++;
		q[c].fla=true;
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	cin>>t;
	while(t--){
		ans=0,n1=0,n2=0,n3=0;
		for(int i=1;i<=n;i++){
			q[i].fla=false;
		}
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>q[i].fir>>q[i].sec>>q[i].thi;
			if(q[i].sec!=0 || q[i].thi!=0) teshu=false;
		}
		if(teshu){
			sort(q+1,q+1+n,cmp1);
			for(int i=1;i<=(n/2);i++) ans+=q[i].fir;
			cout<<ans<<endl;
			continue;
		}
		else{
			for(int i=1;i<=n;i++){
				if(n1<=(n/2)){
					sort(q+1,q+1+n,cmp1);
					a=1;
					while(q[a].fla!=false) a++;
					if(q[a].fla==false) x=q[a].fir;
					else x=0;
				}
				if(n2<=(n/2)){
					sort(q+1,q+1+n,cmp2);
					b=1;
					while(q[b].fla!=false) b++;
					if(q[b].fla==false) y=q[b].sec;
					else y=0;
				}
				if(n3<=(n/2)){
					sort(q+1,q+1+n,cmp3);
					c=1;
					while(q[c].fla!=false) c++;
					if(q[c].fla==false) z=q[c].thi;
					else z=0;
				}
				solve1(max(max(x,y),max(x,z)));
			}
			cout<<ans<<endl;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
