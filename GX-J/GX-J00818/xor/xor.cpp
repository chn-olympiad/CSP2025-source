#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in",'w',stdin);
	freopen("xor.out",'r',stdout);
	int n,k;
	cin>>n>>k;
	if(k==0){
		if(n==2){
			cout<<1;
		}
		if(n>2){
			int s=0;
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					if(j-i!=0&&(j-i)%2==0){
						s++;
					}
				}
			}
			cout<<s;
		}
	}else{
		cout<<-1;
	}
	return 0;
}
