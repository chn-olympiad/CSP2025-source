#include<iostream>
using namespace std;

const int maxn = 5*1e5+10;
int n,k,a[maxn],sum[maxn],tmp;

string turnto2(int a){
	long long cnt = 1;
	string s ;
	while(cnt < a) cnt*=2;
	while(cnt > 0){
		if(a - cnt >= 0){
			s += "1";
			a -= cnt;
		}else s += "0";
		cnt/=2;
	}
	return s;
}

void jisuan(int a,int b){
	string sa = turnto2(a),sb = turnto2(b);
	//cout<< sa << " " << sb << endl;
	int al = sa.length(),bl = sb.length();
	while(al < bl){
		al++;
		sa = "0" + sa;
	}
	while(bl < al){
		bl++;
		sb = "0"+sb;
	}
	//cout << sa << " " << sb << endl;
	string cnt ;
	for(int i = 0;i < al;i++){
		int n = sa[i]-'0',m = sb[i]-'0';
		if(n == m) cnt = cnt + "0";
		 else cnt = cnt + "1";
	}
	//cout << cnt << endl;
	int num = 0,cl = cnt.length(),q = 1;
	for(int i = cl-1;i >= 0;i--){
		num += q*(cnt[i]-'0');
		q*=2;
	}
	//cout << num << endl;
	tmp = num;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	jisuan(2,0);
	cin >> n >> k;
	sum[0] = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		sum[i] = a[i] ^ sum[i-1];
	}
	int ans = 0;
	if(k == 1){
		for(int i = 1;i <= n;i++){
			if(a[i] == 1) ans++;
		}
	}else if(k == 0){
		for(int i = 1;i <= n;i++){
			if(a[i] == 0) ans++;
			 else if(a[i] == 1 && i+1 <= n){
				if(a[i+1] == 1) ans++,i++;				
			 }
		}
	}else{
		/*int last = 0;
		for(int i = 1;i <= n;i++){
			int m = last ^ a[i];
			if(m == k || a[i] == k){
				ans++;
				last = a[++i];
			}else last = m;
		}*/
		int cut = 0;
		for(int i = 1;i <= n;i++){
			for(int k = cut;k <= i-1;k++){
				jisuan(sum[i],sum[k]);
				if(tmp == k){
					cut = i;
					ans++;
					break;
				}	
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
