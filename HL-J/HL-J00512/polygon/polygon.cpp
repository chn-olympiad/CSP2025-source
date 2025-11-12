#include<bits/stdc++.h>
using namespace std;
int a[1000],s[1000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c=0,w=0;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}int b=a[0];
	sort(a,a+n*m);
	for(int i=n*m-1;i>=0;i--){
		c++;
		s[c-1]=a[i];
	}for(int i=0;i<n*m;i++){
		if(s[i]==b){
			w=i+1;
		}
	}
	for(int i=0;i<n*m;i++){
		if(w<=n){
			cout<<1<<" "<<w;
			return 0;
		}else if(w>n){
			if(w%n==0){
				cout<<w/n<<" "<<1;
				return 0;
			}if(w%n!=0){
				if(w/n%2==1){
					cout<<w/n+1<<" "<<n-w%n+1;
					return 0;
				}if(w/n%2==0){
					cout<<w/n+1<<" "<<w%n;
					return 0;
				}
			}
		}
	}
	return 0;
}
