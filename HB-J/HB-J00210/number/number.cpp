#include <bits/stdc++.h>
using namespace std;
string s;
long long a[100000000];
long long cnt;
long long sum1;
long long sum2;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			 a[cnt]=s[i]-'0';
			 cnt++;
			 if(s[i]=='0')
                sum1++;
             else sum2++;
		}
	}
	sort(a,a+cnt,cmp);
	if(sum2==0&&sum1>=2) cout<<0;
	else{
        for(long long i=0;i<cnt;i++){
            cout<<a[i];
        }
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
