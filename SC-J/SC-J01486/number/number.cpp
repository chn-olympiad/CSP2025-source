#include<bits/stdc++.h>
using namespace std;
string s;
long long num_cnt,cnt,a[1000005];
char c;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if('0'<=s[i]&&s[i]<='9'){
			c=s[i];
			num_cnt++;
		}
	}
	if(num_cnt==1) cout<<c;
	else if(num_cnt==len){
		for(int i=0;i<len;i++){
			s[i]-=48;
			a[i]=s[i];
		}
		sort(a,a+len,cmp);
		for(int i=0;i<len;i++) cout<<a[i];
	}else{
		for(int i=0;i<len;i++){
			if('0'<=s[i]&&s[i]<='9'){
				cnt++;
				s[i]-=48;
				a[i]=s[i];
			}
		}
		sort(a,a+len,cmp);
		for(int i=0;i<cnt;i++) cout<<a[i];
	}
	return 0;
} 