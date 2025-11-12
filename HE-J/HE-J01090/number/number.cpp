#include<bits/stdc++.h>
using namespace std;
string s;
int m;
int a[1000000];
int ans;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
		    a[m]=s[i]-'0';
			m++;
		}
	}
	sort(a,a+m,cmp);
	for(int i=0;i<m;i++){
		ans=ans*10+a[i];
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
