#include<bits/stdc++.h>

using namespace std;
const int N=110;

int n,m;
int s[N];
int a[N];
int c,r;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int sq=n*m;
	for(int i=1;i<=sq;i++){
		cin >> s[i];
	}
	int R=s[1];
	sort(s+1,s+sq+1);
	for(int i=sq,j=1;i>=1;i--){
		a[j]=s[i];
		j++;
	}
	int p=0;
	for(int i=1;i<=sq;i++){
		if(R==a[i]){
			p=i;
			break;
		}
	}
	int pvp=1;
	bool f=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(p==pvp){
				c=i;
				f=1;
				if(i%2==1){
					r=j;
				}
				else{
					r=n+1-j;
				}
				break;	
			}
			pvp++;
		}
		if(f==1){
			break;
		}
	}
	cout << c  <<" "<< r;
	return 0;
}