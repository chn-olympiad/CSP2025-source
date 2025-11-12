#include<bits/stdc++.h>
using namespace std;
const int N=110;
int a[N]; 
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m>>a[1];
	int ct=n*m,x=a[1];
	for(int i=2;i<=ct;i++){
		cin>>a[i];
	}
	sort(a+1,a+ct+1,cmp);
	for(int i=1;i<=ct;i++){
		if(a[i]==x){
			cout<<(i-1)/m+1<<" ";
			if(((i-1)/m+1)%2==0){
				cout<<m-((i-1)%m);
			}
			else{
				cout<<(i-1)%m+1;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
