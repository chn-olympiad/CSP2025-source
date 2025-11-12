#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char a[N];
long long ans[N],cnt;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long p=s.size();
	for(long long i=0;i<p;i++){
		char t=s[i];
		if(t=='1'||t=='2'||t=='3'||t=='4'||t=='5'||t=='6'||t=='7'||t=='8'||t=='9'){
			a[i]=t;
		}
		if(t=='0'){
            cnt++;
		}
	}
	sort(a,a+p,cmp);
	for(long long i=0;i<p;i++){
		if(a[i]!=0){
			cout<<a[i];
		}
	}
	while(cnt--){
        cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
