#include<bits/stdc++.h>
using namespace std;
int a1[100005],a2[100005],a3[100005];
int t,n;
int nb;
long long mx=0;
int cv1=0,cv2=0;
void dfs(int i,int a,int b,int c,long long sum){
	if(sum>mx) mx=sum;
	if((a>=nb&&b>=nb)||(a>=nb&&c>=nb)||(b>=nb&&c>=nb)) return;
	if(i>n) return;
	if(a<nb&&b<nb&&c<nb){
		dfs(i+1,a+1,b,c,sum+a1[i]);
		dfs(i+1,a,b+1,c,sum+a2[i]);
		dfs(i+1,a,b,c+1,sum+a3[i]);
	}else if(a>=nb){
		dfs(i+1,a,b+1,c,sum+a2[i]);
		dfs(i+1,a,b,c+1,sum+a3[i]);
	}else if(b>=nb){
		dfs(i+1,a+1,b,c,sum+a1[i]);
		dfs(i+1,a,b,c+1,sum+a3[i]);
	}else if(c>=nb){
		dfs(i+1,a+1,b,c,sum+a1[i]);
		dfs(i+1,a,b+1,c,sum+a2[i]);
	}
	if(i==n) return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	cout<<endl;
	while(t--){
		cin>>n;
		nb=n/2;
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
		}
		for(int i=1;i<=n;i++){
			if(a2[i]!=0)
				cv1=1;
			if(a3[i]!=0)
				cv2=1;
		}
		if(!cv1&&!cv2){
			sort(a1+1,a1+n+1);
			for(int i=n;i>n/2;i--){
				mx+=a1[i];
			}
			cout<<mx<<endl;
			mx=-1;
			
		}else{
			dfs(1,0,0,0,0);
			cout<<mx<<endl;
			mx=-1;
		}
	}
	return 0;
}
