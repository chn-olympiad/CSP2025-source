#include<bits/stdc++.h>
using namespace std;
int	main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin >> s;
	int sl = s.size();
	int index = 0;
	char ss[1000010];
	for(int i=0;i<sl;++i){
		if(s[i] >= '0' && s[i] <= '9') {ss[index] = s[i];index++;}
	}
	sort(ss,ss+index,greater<char>());
	int hd = 0;
	while(ss[hd] == '0' && index - hd > 1) hd++;
	for(int i=hd;i<index;++i) cout<<ss[i];
	return 0;
}
