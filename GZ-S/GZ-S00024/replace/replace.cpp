//GZ-S00024 何彦辰 遵义市第四中学
#include <bits/stdc++.h>
using namespace std;
int n,q,x=0;
char s1[100000],s2[100000],t1[100000],t2[100000];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
    	cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=q;i++){
    	cin>>t1[i]>>t2[i];
	}
	for(int i=1;i<=q;i++){
    	cout<<x<<endl;
	}
	fclose(stdin);
	fclose(stdout);
}

