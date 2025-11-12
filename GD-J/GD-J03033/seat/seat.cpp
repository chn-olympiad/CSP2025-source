#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a,s;
	cin>>n>>m;
	int list[n*m];
	for(int i=0;i<(n*m);i++){
		cin>>list[i];
	}
	s=list[0];
	for(int i=0;i<(n*m);i++){
		for(int j=0;j<n*m;j++){
			if(list[j]<list[i]){
				a=list[j];
				list[j]=list[i];
				list[i]=a;
			}
		}
	}
	for(int i=0;i<n*m;i++){
		if(list[i]==s){
			s=i;
			s++;
		}
	}
	for(int i=0;i<n*m;i+=2){
		if(n*i+1<=s&&s<=n*(i+1)){
			if(s%n!=0){
				cout<<i+1<<" "<<s%n;
				return 0;
			}
			else if(s%n==0){
				cout<<i+1<<" "<<n;
				return 0;
			}
		}
		else{
			if(s%n==0){
				cout<<i+2<<" "<<1;
				return 0;
			}
			else{
				cout<<i+2<<" "<<n-(s%n)+1;
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
}
