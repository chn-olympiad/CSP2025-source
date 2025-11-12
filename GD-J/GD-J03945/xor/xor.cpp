/*#include<bits/stdc++.h>
using namespace std;
int n,k,a,b,ans,c;
set<int> s;
int main(){
	freopen("xor5.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d" ,&n,&k);
	for(int i = 1;i <= n;i++){
		scanf("%d" ,&a);
		c ^= a;
		if(a == k){
			ans++;
			c = 0;
			s.clear();
			continue;
		}
		b = k ^ a;
		if(s.find(b) != s.end()){
			ans++;
			c = 0;
			s.clear();
		}else{
			s.insert(c);
		}
	}
	printf("%d" ,ans);
	return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
int n,k,a[600000],b,c,ans,d;
set<int> s;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d" ,&n,&k);
	if(k == 0){
		d = 0;
		for(int i = 1;i <= n;i++){
			scanf("%d" ,&a[i]);
			if(a[i] == 0){
				d = 0;
				ans++;
			}else{
				d++;
				if(d == 2){
					ans++;
					d = 0;
				}
			}
		}
		printf("%d" ,ans);
		return 0;
	}
	for(int i = 1;i <= n;i++){
		scanf("%d" ,&a[i]);
		if(a[i] == k){
			ans++;
			c = i + 1;
			continue;
		}
		b = k ^ a[i];
		for(int j = i - 1;j >= c;j--){
			if(a[j] == b){
				ans++;
				c = i + 1;
				break;
			}
			b ^= a[j];
		}
	}
	printf("%d" ,ans);
	return 0;
}
