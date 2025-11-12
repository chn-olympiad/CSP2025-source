#include<bits/stdc++.h>
using namespace std;
int cnt[10]; 
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char t;
	while(cin>>t){
		if(isdigit(t)){
			cnt[t-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(cnt[i]--){
			printf("%d",i);
		}
	}
	return 0;
}
//低血糖力（悲）酒店早餐好难吃我没吃多少。我右边同学能不能不要再用椅子敲击地面了（怒） 
