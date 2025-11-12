#include <bits/stdc++.h>
using namespace std;
int n,k,a[500010],b,x1,x2,o;
long long s1,s2,ans1,ans2,tmp1,tmp2,tmp3;
bool w[500010],v;
int npow(int s){
	if(s == 1) return 0;
	for(int i = 1;i<=s;i++){
		s /= 2;
		b++;
		if(s == 1) break;
	}
	return b;
}
int ejz1(int x1){
	if(x1 == 0) return 0;
	for(int i = 1;i<=x1;i*=2){
		if(i > x1) s1 =  i/2;
		ans1 += int(pow(10,npow(s1)));
		x1 -= s1;
		ejz1(x1);
	}
	return ans1;
}
int ejz2(int x2){
	if(x2 == 0) return 0;
	for(int i = 1;i<=x2;i*=2){
		if(i > x2) s2 =  i/2;
		ans2 += int(pow(10,npow(s2)));
		x2 -= s2;
		ejz2(x2);
	}
	return ans2;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
		if(a[i] == k){
			tmp1++;
			w[i] = 1;
			o = 1;
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			if(a[j] != 1) v = 1;
		}
		if(v == 0){
			if(k == 0){
				tmp2 = n/2;
				o = 2;
			}
		}
		//x1 = a[i];
		//x2 = a[i+1];
		//ejz1(x1);
	//	ejz2(x2);
		//if(ans1 > ans2){
		//	for(int i = 1;i<=ans1;i++){
		//		if(k == 1){
		//			if((ans1 & 1) == (ans2 & 1) && w[i] == 0 && w[i+1] == 0){
		//			tmp3++;
		//			ans1 = (ans1 >> 1);
		//			ans2 = (ans2 >> 1);
		//			}
		//		}else if(k == 0){
		//			if((ans1 & 1) != (ans2 & 1) && w[i] == 0 && w[i+1] == 0){
		//			tmp3++;
		//			ans1 = (ans1 >> 1);
		//			ans2 = (ans2 >> 1);
		//			}
		//		}
		//	}
		//}else if(ans1 < ans2){
		//	for(int i = 1;i<=ans2;i++){
		//		if(k == 1){
		//			if((ans1 & 1) == (ans2 & 1) && w[i] == 0 && w[i+1] == 0){
		//			tmp3++;
		//			ans1 = (ans1 >> 1);
		//			ans2 = (ans2 >> 1);
		//			}
		//		}else if(k == 0){
		//			if((ans1 & 1) != (ans2 & 1) && w[i] == 0 && w[i+1] == 0){
		//			tmp3++;
		//			ans1 = (ans1 >> 1);
		//			ans2 = (ans2 >> 1);
				//	}
				//}
			//}
	}
	if(o == 1) cout << tmp1;
	else if(o == 2)cout << tmp2;
	else cout << tmp3;
	return 0;
}
