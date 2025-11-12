#include <bits/stdc++.h>
using namespace std;
int r;
int a[110];
int m,n;
bool cmp(int a,int b){
	return a>b;
}
int main()
{
	freopen("fre.in","r",stdin);
	freopen("fre.out","w",stdout);
	cin >> m >> n;
	cin >> r;
	a[1]=r;
	for(int i=2;i<=m*n;i++){
		cin >> a[i];
	}
	sort(a+1,a+m*n+1,cmp);
	for(int i=1;i<=m*n;i++){
		if(a[i]==r){
			cout<<(i-1)/n+1<<" ";
			if((i-1)/n+1==1){
				cout << i<<endl;
				return 0;
			}else if(((i-1)/n+1)%2==0){
				cout << n-(i%n)+1<<endl;
				return 0;
			}else{
				if(i%n==0){
					cout << n;
					return 0;
				}
				cout << (i%((i-1)/n+1)?i%((i-1)/n+1):1)<<endl;
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
