#include <bits/stdc++.h>
using namespace std;
int f(int a,int b){
	if(a==1){
		return 0;
	}
	if(a%2==0){
		f(a-1,b+2);
	}else{
		f(a-1,b+1);
	}
	
};
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n;
	cin>>n;
	int sum=1,cnt=0;
	for(int i=0;i<n;i++){
		sum++;
		cnt++;
		f(sum,cnt);
	}
	cout<<sum<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}