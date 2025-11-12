#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string r;
	cin>>r;
	//int a[r.size()];
	long long as=0;
	for(long long i=0;i<r.size();i++){
		if(r[i]>='0'&&r[i]<='9'){
			a[as]=r[i]-'0';
			as++;
		}
	}
	sort(a,a+r.size(),cmp);
	for(long long i=0;i<as;i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
