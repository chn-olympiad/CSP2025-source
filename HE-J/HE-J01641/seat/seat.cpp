#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int k[100001];
	for(int i=1;i<=n*m;i++){
		cin>>k[i];
	}
	int p=k[1];
	int flag=0;
	sort(k+1,k+n*m,cmp);

	for(int i=1;i<=n*m;i++){
		if(k[i]==p){
			flag=i;	
		}
	}
	int hang=0,lie=0;
	if(flag%n==0){
		lie=flag/n;
	}
	else if(flag%n!=0){
		lie=flag/n+1;
	}
	if(lie%2==1){
		hang=flag-n*(lie-1); 
	}else if(lie%2==0){
		hang=n-(flag-n*(lie-1))+1;
	}
	cout<<lie<<" "<<hang;
	fclose(stdin);
	fclose(stdout);
	return 0;
	}
