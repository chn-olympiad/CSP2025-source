#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
char a[N];
int num[N];
string s;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int cnt=0;
	int n=s.size();
	for(int i=1;i<=n;i++){
		a[i]=s[i-1];
		if(a[i]>='0' && a[i]<='9'){
			cnt++;
			num[cnt]=a[i]-'0';
		}
	}
	sort(num+1,num+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		cout<<num[i];
	}
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
