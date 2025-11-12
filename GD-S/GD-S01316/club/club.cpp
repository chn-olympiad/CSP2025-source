#include<bits/stdc++.h>
using namespace std;
struct node{
	int _first;
	int _second;
	int _third;
}a[200010];
int t,n,maxn,s1,s2,s3;
bool fa,fb;
bool cmpa(node x,node y){
	return x._first>y._first;
}
bool cmpb(node x,node y){
	return max(x._first,x._second)>max(y._first,y._second);
}
void dfs(int d,int sum){
	if(d==n+1){
		maxn=max(maxn,sum);
		return;
	}
	if(s1<n/2){
		s1++;
		dfs(d+1,sum+a[d]._first);
		s1--;
	}
	if(s2<n/2){
		s2++;
		dfs(d+1,sum+a[d]._second);
		s2--;
	}
	if(s3<n/2){
		s3++;
		dfs(d+1,sum+a[d]._third);
		s3--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]._first>>a[i]._second>>a[i]._third;
			if(a[i]._second||a[i]._third){
				fa=true;
			}
			if(a[i]._third){
				fb=true;
			}
		}
		if(!fa){
			sort(a+1,a+n+1,cmpa);
			int sum=0;
			for(int i=1;i<=n/2;i++){
				sum+=a[i]._first;
			}
			cout<<sum<<endl;
		}else if(!fb){
			sort(a+1,a+n+1,cmpb);
			int sum=0,pl1=0,pl2=0;
			for(int i=1;i<=n;i++){
				if(pl1==n/2){
					sum+=a[i]._second;
					pl2++;
				}else if(pl2==n/2){
					sum+=a[i]._first;
					pl1++;
				}else if(pl1<n/2&&pl2<n/2){
					if(a[i]._first>a[i]._second){
						sum+=a[i]._first;
						pl1++;
					}else{
						sum+=a[i]._second;
						pl2++;
					}
				}
			}
			cout<<sum<<endl;
		}else{
			dfs(1,0);
			cout<<maxn<<endl;
			s1=s2=s3=maxn=0;
		}
		fa=fb=false;
	}
	return 0;
}
