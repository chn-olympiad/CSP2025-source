#include <bits/stdc++.h>
using namespace std;
int n,m,b,a[110],s[11][11],cnt=1,k;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;

for(int i=1;i<=n*m;i++){
		cin>>a[i];

}
b=a[1];
sort(a,a+n*m+1);
for(int i=m;i>=1;i--){
	for(int j=n;j>=1;j--){
		s[j][i]=a[cnt];
		cnt++;
	}
}
for(int i=1;i<=n;i++){
	for(int j=1;j<=m;j++){
		if(i%2==0){
			for(int h=1;h<=j/2;h++){
			int t=m;
			k=s[h][i];
			s[h][i]=s[t][i];
			s[t][i]=k;

			t--;
		}
	}
}
}
for(int i=1;i<=n;i++){
	for(int j=1;j<=m;j++){
		if(s[i][j]==b) cout<<j<<" "<<i;
	}
}
return 0;
}
