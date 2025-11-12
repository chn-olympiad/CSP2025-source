#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int student[105]={0};
bool a(int a,int b){
	return a>b;
} 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>student[i];
	}
	int ming=student[0];
	sort(student,student+n*m,a);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(student[n*i+j]==ming){
				if((i+1)%2==0){
					cout<<i+1<<" "<<n-j;
					return 0;
				}
				else{
					cout<<i+1<<" "<<j+1;
					return 0;
				}
			}
		}
	}
	return 0;
}