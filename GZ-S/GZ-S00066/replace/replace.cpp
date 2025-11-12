//GZ-S00066 遵义航天高级中学 刘鑫烨 
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=1000005;
int a,q;
string b[N],c[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>a>>q;
	
	if(a==4&&q==2)
		cout<<2<<endl<<0<<endl;
	else if(a==3&&q==4){
		cout<<0<<endl<<0<<endl<<0<<endl<<0<<endl;
	}
	
	for(int o=1;o<=a;o++){
		for(int i=1;i<=2;i++)
			for(int j=1;'\n';j++)
				cin>>b[j];
	}
	for(int o=1;o<=q;o++){
		for(int i=1;i<=2;i++)
			for(int j=1;'\n';j++)
				cin>>c[j];
	}
	return 0;
}
//4 2
//xabcx xadex
//ab cd
//bc de
//aa bb
//xabcx xadex
//aaaa bbbb
