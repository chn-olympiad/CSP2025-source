#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",in);
	freopen("seat.out","w",out);
	
	int n,m;
	int s[210];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i];
	}
	int a=s[1];
	int t;
	for(int i=n*m;i>=1;i--){
		for(int j=1;j<=i;j++){
			if(s[i]>s[j]){
				t=s[i];
				s[i]=s[j];
				s[j]=t;
			}
		}
	}
	int w;
	for(int i=1;i<=n*m;i++){
		if(s[i]==a){
			w=i;
			break;
		}
	}
	if(w%n==0){
		cout<<w/n<<" "<<n;
		return 0;
	}
	else{
		if(((w/n)+1)%2!=0){
			cout<<(w/n)+1<<" "<<w%n;
		}
		else{
			cout<<(w/n)+1<<" "<<n-(w%n)+1;
		}
	}
	return 0;
}
