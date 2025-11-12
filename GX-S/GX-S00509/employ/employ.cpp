#include<iostream>
using namespace std;
const int MAXN=1005;
long long s[MAXN];
int c[MAXN];
int fail_person=0;
int pass_person=0;
int cnt_p=0;
int main(){
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	int n,m;
	
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		cin>>c[i];
		if(s[i]==1){
			pass_person++;
			n--;
		}
		if(s[i]==0){
			fail_person++;
			n--;
			if(fail_person>=c[i])
			n--;
		}
		if(pass_person>=m)
			cnt_p++;
		
	}
	cout<<cnt_p;
return 0;
}
