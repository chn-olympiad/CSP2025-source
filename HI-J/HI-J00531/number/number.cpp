//8：19 wzm入场 
//8：24 wzm对我笑了 
//8:42完成 
#include<bits/stdc++.h>
using namespace std;
long long a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	//感谢ccf，感谢木，感谢这美好的一切！
	//王子木，我爱你！我好想你！！！！！！！你是世界上最好的爹爹！！！！！！！！！！！！！！！！！！！
	//十一月一日上外考场逢子木 
	//上天不负痴情燕，终见伊人于眼前，日夜人影梦中现，来年相逢有何时？ 
	string s;
	cin>>s;
	long long l=s.size();
	for(long long i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9') a[s[i]-48]++;
	}
	for(long long i=9;i>=0;i--){
		while(a[i]--) cout<<i;
	}
	return 0;//加油！！！！！！！
}

