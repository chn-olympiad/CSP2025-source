#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,no,arr;
	int tong;
}a[100010][5],c[100010][5];
bool operator < (node x,node y){
	return x.x>y.x||(x.x==y.x&&x.no<y.no);
}
bool cmp(node x,node y){
	return x.x>y.x||(x.x==y.x&&x.no<y.no);
}
void SSort(node &x,node &y,node &z){
	if(x.x<y.x||(x.x==x.x&&x.no>y.no))
		swap(x,y);
	if(y.x<z.x||(y.x==z.x&&y.no>z.no))
		swap(y,z);
	if(x.x<z.x||(x.x==z.x&&x.no>z.no))
		swap(x,z);
	cout<<x.x<<' '<<y.x<<' '<<z.x<<'\n';
}
bool cmp1(pair<int,int> a,pair<int,int>b){
	return a.first>b.first||(a.first==b.first&&a.second>b.second); 
}
bool cmp2(pair<int,int> a,pair<int,int>b){
	return a.second>b.second||(a.second==b.second&&a.first>b.first); 
}
priority_queue<node,vector<node> >q1,q2,q3;
int ans1,ans2,ans3,n,ans;
int b[100010][4];
void dfs(int sum1,int sum2,int sum3,int x,int sum){
	if(x>=n){
		ans=max(ans,sum);
		return;
	}
	if(sum1+1<=n/2)
		dfs(sum1+1,sum2,sum3,x+1,sum+b[x+1][1]);
	if(sum2+1<=n/2)
		dfs(sum1,sum2+1,sum3,x+1,sum+b[x+1][2]);
	if(sum3+1<=n/2)
		dfs(sum1,sum2,sum3+1,x+1,sum+b[x+1][3]);
	return;
}
int tong[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		while(q1.size())
			q1.pop();
		while(q2.size())
			q2.pop();
		while(q3.size())
			q3.pop();
		ans1=ans2=ans3=0;
		bool flagA=true,flagB=true;
		cin>>n;
		if(n==2){
			int x,y;
			cin>>x>>y;
			cout<<max(x,y)<<'\n';
			continue;
		}
		if(n<=10){
			for(int i=1;i<=n;i++)
				cin>>b[i][1]>>b[i][2]>>b[i][3];
			dfs(0,0,0,0,0);
			cout<<ans<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>c[i][j].x;
				c[i][j].no=j;
				c[i][j].arr=i;
			}
			if(c[i][3].x!=0)
				flagA=flagB=0;
			else
				if(c[i][2].x!=0)
					flagA=0;
		}
		if(flagA){
			vector<int>vec;
			vec.clear();
			for(int i=1;i<=n;i++)
				vec.push_back(c[i][1].x);
			sort(vec.begin(),vec.end());
			int ans=0;
			for(int i=n/2;i<n;i++)
				ans+=vec[i];
			cout<<ans<<'\n';
			continue;
		}
		if(flagB){
			vector<pair<int,int> >vec;
			vec.clear();
			for(int i=1;i<=n;i++)
				vec.push_back(make_pair(c[i][1].x,c[i][2].x));
			sort(vec.begin(),vec.end(),cmp1);
			int ans1=0,ans2=0;
			for(int i=0;i<n/2;i++)
				ans1+=vec[i].first;
			for(int i=n/2;i<n;i++)
				ans1+=vec[i].second;
			sort(vec.begin(),vec.end(),cmp2);
			for(int i=0;i<n/2;i++)
				ans2+=vec[i].second;
			for(int i=n/2;i<n;i++)
				ans2+=vec[i].first;
			cout<<max(ans1,ans2)<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				a[i][j]=c[i][j];
			}
			/*
			if(a[i][1].x<a[i][2].x||(a[i][1].x==a[i][2].x&&a[i][1].no>a[i][2].no))
				swap(a[i][1],a[i][2]);
			if(a[i][2].x<a[i][3].x||(a[i][2].x==a[i][3].x&&a[i][2].no>a[i][3].no))
				swap(a[i][2],a[i][3]);
			if(a[i][1].x<a[i][3].x||(a[i][1].x==a[i][3].x&&a[i][1].no>a[i][3].no))
				swap(a[i][1],a[i][3]);
			if(a[i][1].x<a[i][2].x||(a[i][1].x==a[i][2].x&&a[i][1].no>a[i][2].no))
				swap(a[i][1],a[i][2]);
			if(a[i][2].x<a[i][3].x||(a[i][2].x==a[i][3].x&&a[i][2].no>a[i][3].no))
				swap(a[i][2],a[i][3]);
			if(a[i][1].x<a[i][3].x||(a[i][1].x==a[i][3].x&&a[i][1].no>a[i][3].no))
				swap(a[i][1],a[i][3]);
			*/
			sort(a[i]+1,a[i]+4,cmp);
			if(a[i][1].no==1)
				q1.push(a[i][1]),ans1+=a[i][1].x;
			if(a[i][1].no==2)
				q2.push(a[i][1]),ans2+=a[i][1].x;
			if(a[i][1].no==3)
				q3.push(a[i][1]),ans3+=a[i][1].x;
		}
		while(q1.size()>n/2){
			node x=q1.top();
			ans1-=x.x;
			q1.pop();
			if(a[x.arr][1].tong==0){
				a[x.arr][1].tong=1;
				if(a[x.arr][2].tong==0)
					if(a[x.arr][2].no==2)
						q2.push(a[x.arr][2]),ans2+=a[x.arr][2].x;
					else
						q3.push(a[x.arr][2]),ans3+=a[x.arr][2].x;
				else
					if(a[x.arr][3].no==2)
						q2.push(a[x.arr][3]),ans2+=a[x.arr][3].x;
					else
						q3.push(a[x.arr][3]),ans3+=a[x.arr][3].x;
			}
			else
				if(a[x.arr][2].tong==0){
					a[x.arr][2].tong=1;
					if(a[x.arr][3].no==2)
						q2.push(a[x.arr][3]),ans2+=a[x.arr][3].x;
					else
						q3.push(a[x.arr][3]),ans3+=a[x.arr][3].x;
				}
		}
		while(q2.size()>n/2){
			node x=q2.top();
			ans1-=x.x;
			q2.pop();
			if(a[x.arr][1].tong==0){
				a[x.arr][1].tong=1;
				if(a[x.arr][2].tong==0)
					if(a[x.arr][2].no==1)
						q1.push(a[x.arr][2]),ans2+=a[x.arr][2].x;
					else
						q3.push(a[x.arr][2]),ans3+=a[x.arr][2].x;
				else
					if(a[x.arr][3].no==1)
						q1.push(a[x.arr][3]),ans2+=a[x.arr][3].x;
					else
						q3.push(a[x.arr][3]),ans3+=a[x.arr][3].x;
			}
			else
				if(a[x.arr][2].tong==0){
					a[x.arr][2].tong=1;
					if(a[x.arr][3].no==1)
						q1.push(a[x.arr][3]),ans2+=a[x.arr][3].x;
					else
						q3.push(a[x.arr][3]),ans3+=a[x.arr][3].x;
				}
		}
		while(q3.size()>n/2){
			node x=q3.top();
			ans1-=x.x;
			q3.pop();
			if(a[x.arr][1].tong==0){
				a[x.arr][1].tong=1;
				if(a[x.arr][2].tong==0)
					if(a[x.arr][2].no==1)
						q1.push(a[x.arr][2]),ans2+=a[x.arr][2].x;
					else
						q2.push(a[x.arr][2]),ans3+=a[x.arr][2].x;
				else
					if(a[x.arr][3].no==1)
						q1.push(a[x.arr][3]),ans2+=a[x.arr][3].x;
					else
						q2.push(a[x.arr][3]),ans3+=a[x.arr][3].x;
			}
			else
				if(a[x.arr][2].tong==0){
					a[x.arr][2].tong=1;
					if(a[x.arr][3].no==1)
						q1.push(a[x.arr][3]),ans2+=a[x.arr][3].x;
					else
						q2.push(a[x.arr][3]),ans3+=a[x.arr][3].x;
				}
		}
		while(q1.size()>n/2){
			node x=q1.top();
			ans1-=x.x;
			q1.pop();
			if(a[x.arr][1].tong==0){
				a[x.arr][1].tong=1;
				if(a[x.arr][2].tong==0)
					if(a[x.arr][2].no==2)
						q2.push(a[x.arr][2]),ans2+=a[x.arr][2].x;
					else
						q3.push(a[x.arr][2]),ans3+=a[x.arr][2].x;
				else
					if(a[x.arr][3].no==2)
						q2.push(a[x.arr][3]),ans2+=a[x.arr][3].x;
					else
						q3.push(a[x.arr][3]),ans3+=a[x.arr][3].x;
			}
			else
				if(a[x.arr][2].tong==0){
					a[x.arr][2].tong=1;
					if(a[x.arr][3].no==2)
						q2.push(a[x.arr][3]),ans2+=a[x.arr][3].x;
					else
						q3.push(a[x.arr][3]),ans3+=a[x.arr][3].x;
				}
		}
		while(q2.size()>n/2){
			node x=q2.top();
			ans1-=x.x;
			q2.pop();
			if(a[x.arr][1].tong==0){
				a[x.arr][1].tong=1;
				if(a[x.arr][2].tong==0)
					if(a[x.arr][2].no==1)
						q1.push(a[x.arr][2]),ans2+=a[x.arr][2].x;
					else
						q3.push(a[x.arr][2]),ans3+=a[x.arr][2].x;
				else
					if(a[x.arr][3].no==1)
						q1.push(a[x.arr][3]),ans2+=a[x.arr][3].x;
					else
						q3.push(a[x.arr][3]),ans3+=a[x.arr][3].x;
			}
			else
				if(a[x.arr][2].tong==0){
					a[x.arr][2].tong=1;
					if(a[x.arr][3].no==1)
						q1.push(a[x.arr][3]),ans2+=a[x.arr][3].x;
					else
						q3.push(a[x.arr][3]),ans3+=a[x.arr][3].x;
				}
		}
		while(q3.size()>n/2){
			node x=q3.top();
			ans1-=x.x;
			q3.pop();
			if(a[x.arr][1].tong==0){
				a[x.arr][1].tong=1;
				if(a[x.arr][2].tong==0)
					if(a[x.arr][2].no==1)
						q1.push(a[x.arr][2]),ans2+=a[x.arr][2].x;
					else
						q2.push(a[x.arr][2]),ans3+=a[x.arr][2].x;
				else
					if(a[x.arr][3].no==1)
						q1.push(a[x.arr][3]),ans2+=a[x.arr][3].x;
					else
						q2.push(a[x.arr][3]),ans3+=a[x.arr][3].x;
			}
			else
				if(a[x.arr][2].tong==0){
					a[x.arr][2].tong=1;
					if(a[x.arr][3].no==1)
						q1.push(a[x.arr][3]),ans2+=a[x.arr][3].x;
					else
						q2.push(a[x.arr][3]),ans3+=a[x.arr][3].x;
				}
		}
		cout<<ans1+ans2+ans3<<'\n';
	}
	return 0;
} 
