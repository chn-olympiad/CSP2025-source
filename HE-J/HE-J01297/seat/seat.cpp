#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a=0,z=0,w=0,s=0;
	cin>>n>>m;
	int q[n*m];
	cin>>q[1];
	a=q[1];
	for(int i=2;i<=n*m;i++){
		cin>>q[i];
	}
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=n*m;j++){
			if(q[i]>q[j]){
				z=q[i];
				q[i]=q[j];
				q[j]=z;
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		if(q[i]==a){
			a=i;
			break;
		}
	}
	if(a/n==0||a==n){
		w=1;
		s=a;
	}
	else{
		if(a%n==0){
			w=a/n;
			if(w%2==0){
				s=1;
			}else{
				s=n;
			}
		}else{
			w=a/n+1;
			if(w%2==0){
				s=n-a%n+1;
			}else{
				s=a%n;
			}
		}
		
		
	}
	cout<<w<<" "<<s;
	
	fclose(stdin);
	fclose(stdout);
}
