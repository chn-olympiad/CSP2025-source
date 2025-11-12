#include<bits/stdc++.h>
using namespace std;
int r[1000000];
bool cmp(int x,int y){
	return x>y? 1:0;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	getline(cin,a);
	int k = 1;
	for(int i = 0;i<=a.size()-1;i++){
		if(a[i]>='0'&&a[i]<='9'){
			r[k] = a[i]-'0';
			k++;
		}
	}
	sort(r+1,r+k+1,cmp);
	for(int i = 1;i<=k-1;i++){
		cout<<r[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
