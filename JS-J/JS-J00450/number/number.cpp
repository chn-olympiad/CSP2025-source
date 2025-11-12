#include<bits/stdc++.h>
using namespace std;
//int read();
char c;
vector<int> v;
int ss=0;
string s;
//void write(int x);
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int r=s.size();
	for(int z=0;z<r;z++){
		//if(!('0'<=s[z]&&'9'>=s[z]||'a'<=s[z]&&'z'>=s[z]||'A'<=s[z]&&'Z'>=s[z])) break;
		//cout<<s[z]<<endl;
		if(isdigit(s[z])){
			v.push_back(s[z]^48);
			ss++;
		}
	}
	sort(v.begin(),v.end());
	//cout<<ss<<endl;
	for(int i=ss-1;i>=0;i--){
		putchar(v[i]^48);
	}
	printf("\n");
	return 0;
}
//~ int read(){
	//~ char c;
	//~ int f=1,r=0;
	//~ while(!isdigit(c=getchar())){
		//~ if(c=='-') f=-1;
	//~ }
	//~ r=c^48;
	//~ while(isdigit(c=getchar())){
		//~ r=(r*10);
		//~ r+=c^48;
	//~ }
	//~ return r*f;
//~ }
//~ void write(int x){
	//~ if(x<0){
		//~ putchar('-');
		//~ x=-x;
	//~ }
	//~ if(x>9){
		//~ write(x/10);
	//~ }
	//~ putchar(x%10-'0');
//~ }
