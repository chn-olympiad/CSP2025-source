#include<bits/stdc++.h> 

using namespace std;

int n,m;
int s[105];
int a;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++) cin>>s[i];
	a=s[0];
	sort(s,s+n*m);
	int b=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			b++;
			if(s[n*m-b]==a){
				cout<<i+1<<' '<<j+1;
				break;
			}
		}
	}
	return 0;
}

