#include<bits/stdc++.h>
using namespace std;
int n,m;
int s[128];
int mp[16][16];
int l,h;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=m*n;i++){
		cin >> s[i];
	}
	int r=s[1],mid;
	for(int i=1;i<=m*n;i++){
		for(int k=1;k<=m*n;k++){
			if(s[k]<s[k+1]){
				mid=s[k];
				s[k]=s[k+1];
				s[k+1]=mid;
			}
		}
	}
	int ri;
	for(int i=1;i<=m*n;i++){
		if(r==s[i]){
			ri=i;
			break;
		}		
	}
	int lie,hang;
	for(int i=1;i<=m;i++){
		if(ri==0) break;
		if(i%2!=0){
			for(int k=1;k<=n;k++){
				ri--;
				if(ri==0){
					lie=i;
					hang=k;
					break;
				}
			}
		}else{
			for(int k=n;k>=1;k--){
				ri--;	
				if(ri==0){
					lie=i;
					hang=k;
					break;
				}	
			}
		}
	}
	cout << lie << " " << hang;
	return 0;
}
