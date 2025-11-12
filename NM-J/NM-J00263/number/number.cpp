#include<bits/stdc++.h>
using namespace std;
string s;
char ans[100005];
int n=0,o;
bool cmp(int x,int y){
	return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    int len=s.size();
    for(int i=0;i<len;i++){
    	if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
    		n++;
    		ans[n]=s[i];
		}
	}
	sort(ans+1,ans+n+1,cmp);
	for(int i=1;i<=n;i++)cout << ans[i];
    fclose(stdin);
    fclose(stdout);
    return 0;
}