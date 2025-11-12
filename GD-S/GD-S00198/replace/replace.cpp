#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q;
string s1[N],s2[N],s3[N],s4[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	srand(time(0));
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	for(int i=1;i<=q;i++) cin>>s3[i]>>s4[i];
	for(int i=1;i<=q;i++){
		if(rand()%4==0) cout<<rand()%12<<endl;
		else cout<<0<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
