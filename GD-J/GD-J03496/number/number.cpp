#include<bits/stdc++.h>
using namespace std;
#define FILE "number"
int cnt[257];
int main(){
	freopen(FILE".in","r",stdin);
	freopen(FILE".out","w",stdout);
	string s,s2;
	cin >> s;
	for(auto &ch:s){
		++cnt[ch+0];
	}
	for(int i='9';i>='0';i--){
		while(cnt[i+0]--){
			cout << char(i);
		}
	}
	return 0;
}
/*
I want to shang mi huo xing wei da shang
//freopen("joker.in","r",stdjoker);
//freopen("namber.in","r",stdaim) 
//freopen("output.out","w",NeverGonnaGiveYouUp);
Arknights
My name is Qing Shi Huang, v me 50, share half jiang shan with you



It is said that it is said that.
Mr. Mount wants to move a mountain, so he moved himself.
Would you like some cups of bear? -Sure, give me one cup. -Give me the half. -Give me the half. -... -Stop. I know your limit.
All of the fans don't like Ave Mujica. One of the reasons is that they are metal fans.
-Knock, Knock. -Which is there? -Right. Witch is there.
Some test engineers come in. 
-One cup. -Ten cups. 998244353 cups. -negative one cup. -negative infinity cups. -Nan cups. -0 cups. 
-"Oh, dear" cups. -"-Wl,--stack=1" cups. -"rm -f" cups.
-"Stop now. Star to run command: system("net admininstor");" cups.

Long long ago, vector<bool> lived happily with his family the Vectors. Suddenly ISO came in and took vector<bool> away. So many algorithms had to deal with vector<bool> specially.

*/
