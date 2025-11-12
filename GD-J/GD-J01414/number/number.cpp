#include<bits/stdc++.h>
#define debug 0
//debug 1 -> start debug
using namespace std;
int cnt[1024];
void the_true_main(){
	string str;
	cin >> str;
	for(int i = 0;i< (int)str.size();i++){
		if(isdigit(str[i])){
			cnt[str[i] - '0']++;
		}
	}
	for(int i = 9;i>= 0;i--){
		for(int j = 1;j<= cnt[i];j++)cout << i;
	}
}


int main(){
	#if debug == 1
	cout << "start debug\n";
	#else
	//cin.tie(0) -> sync_with_stdio(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	#endif
	the_true_main();
	#if debug == 0
	fclose(stdin);
	fclose(stdout);
	#endif
	return 0;
} 
