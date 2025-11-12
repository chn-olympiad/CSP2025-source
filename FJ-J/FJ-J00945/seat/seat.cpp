#include <bits/stdc++.h>
using namespace std;
bool eg(int x,int y)
{
	if(x>y)return 1;
	else return 0;
}
int a,b,r;
int lst[105];
int main(){
	freopen("seat3.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>a>>b;
	int n=a*b;
	cin>>r;
	for(int k=1;k<=n-1;k++)
		cin>>lst[k];
	sort(lst+1,lst+n+1,eg);
	for(int i=1;i<=b;i++){
		if(i%2==1){
			for(int j=1;j<=a;j++){
				if(r<lst[i*j] && r>lst[i*j+1]){
					if(j==a){
						cout<<i+1<<" "<<a;
						return 0;
					}
					else{
						cout<<i<<" "<<j+1;
						return 0;
					}
				}
			}
		}
		else{
			for(int j=1;j<=a;j++){
				if(r<lst[i*j] && r>lst[i*j+1]){
					if(j==a){
						cout<<i+1<<" "<<1;
						return 0;
					}
					else{
						cout<<i<<" "<<a-(j+1);
						return 0;
					}
				}
			}
		}
	}
	if(b%2==1)cout<<a<<" "<<b;
	else cout<<a<<" "<<1;
}
