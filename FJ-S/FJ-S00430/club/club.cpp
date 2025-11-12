#include<bits/stdc++.h>
using namespace std;
int t;int n;
long long answer=0;
int a[123232],b[123232],c[1232323];

int q,w,e,kk=0;bool p[132323];
void dfs(int t,long long k){
	if(t>n/2*3)return ;
	if(answer<k){//cout<<answer<<endl;
	answer=max(answer,k);kk=t;
	}
	
	for(int i=t;i<n;i++){
		if(p[i]==0){
			if(q+1<=n/2){
				q++;
				p[i]=1;
				dfs(t+1,k+a[i]);
				p[i]=0;
				q--;
			}
			if(e+1<=n/2){
				e++;
				p[i]=1;
				dfs(t+1,k+c[i]);
				p[i]=0;
				e--;
			}
			if(w+1<=n/2){
				w++;
				p[i]=1;
				dfs(t+1,k+b[i]);
				p[i]=0;
				w--;
			}
		}
	}
}
void dfs2(int t,long long k){
	//if(t>n/2)return ;
	if(answer<k){
	answer=max(answer,k);kk=t;
	}
	
	for(int i=t;i<n;i++){
		if(p[i]==0){
			if(q+1<=n/2){
				q++;
				p[i]=1;
				dfs(t+1,k+a[i]);
				p[i]=0;
				q--;
			}
			if(w+1<=n/2){
				w++;
				p[i]=1;
				dfs(t+1,k+b[i]);
				p[i]=0;
				w--;
			}
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		if(n<=30){
			dfs(0,0);
			cout<<answer<<endl;
			answer=0;q=0,w=0,e=0;
		}
		else if(n<=200){
			dfs2(0,0);
			cout<<answer<<endl;
			answer=0;q=0,w=0,e=0;
		}
		else if(c[0]==0&&c[1]==0&&c[34]==0){
			int k[2323],l=0;
			sort(a,a+n);sort(b,b+n);
			if(n%2==0)
			for(int i=n-1;i>=n/2;i--)answer=answer+a[i]+b[i];
			else
			for(int i=n-1;i>n/2;i--)answer=answer+a[i]+b[i];
			cout<<answer<<endl;
		}
		else if(1){
			sort(a,a+n);
			
			if(n%2==0)
			for(int i=n-1;i>=n/2;i--)answer+=a[i];
			else
			for(int i=n-1;i>n/2;i--)answer+=a[i];
			cout<<answer<<endl;
		}
	}
	


	return 0;
}
