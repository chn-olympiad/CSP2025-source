#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int c,r;
int ans,tot=0,sum;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	ans=a[0];
	sort(a,a+n*m);
	int b[110];
	for(int i=n*m-1;i>=0;i--){
		for(int j=tot;j<n*m;j++){
			b[j]=a[i];
		}
		tot++;
	}
	for(int i=0;i<n*m;i++){
		if(b[i]==ans){
			sum=i+1;
			break;
		}
	}
	for(int i=1;i<=m;i++){
		int anss=n;
		if(n%2==1){
			anss++;
		}
		if(sum<=n*i){
			c=i;
			int sss=n*i;
			sss-=sum;
			if(c%2==1){
				for(int j=n;j>=1;j--){
					if(anss==sss){
						r=j;
						break;
					}
					else anss--;
				}
			}
			else{
				anss=0;
				for(int j=1;j<=n;j++){
					if(anss==sss){
						r=j;
						break;
					}
					else anss++;
				}
			}
			break;
		}
		else{
			continue;
		}
	}
	cout<<c<<' '<<r<<endl;
	return 0;
}
/**
4 4
7 20 19 18 17 16 15 14 13 12 11 10 9 8 6 5
*/
/**
100 99 98 97 96 95 94 93 92 91 90 89 87 86 85 84 83 82 81 80 79 78 77 88 75 74 76 73 72 71 70 69 68 67 66 65 64 63 62 61 60 59 58 57 56 55 54 53 52 51 50 49 48 47 46 45 44 43 42 41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1

*/
