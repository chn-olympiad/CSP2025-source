#include<bits/stdc++.h>
using namespace std;
bool cmp(int a1,int b1){
	return a1>b1;
}
int s[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>n>>m;
	int sum=m*n,num;
	cin>>s[1];
	int R=s[1];
	for(int i=2;i<=sum;i++){
		cin>>s[i];
	}
	sort(s+1,s+sum+1,cmp);
	for(int i=1;i<=sum;i++){
		if(s[i]==R){
			num=i;
			break;
		}
	}
	if(((num-1)/n)%2==0){
		cout<<(num-1)/n+1<<" "<<(num-1)%n+1;
	}else{
		cout<<(num-1)/n+1<<" "<<n-((num-1)%n+1)+1;
	} 
	return 0;
}
