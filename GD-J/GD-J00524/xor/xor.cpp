#include<bits/stdc++.h> 
using namespace std;
int er(int a){
	int w[10000];
	int i = 1;
	while(a != 0){
		int b = a%2;
		a = a/2;
		w[i] = b;
		i++;
	}
	int erj = 0;
	for(int j = i-1;j >= 1;j--){
		erj += w[j]*pow(10,j-1);
	}
	return erj;
}
int shi(int a){
	int w[10000];
	int i = 1;
	while(a != 0){
		int b = a%10;
		a = a/10;
		w[i] = b;
		i++;
	}
	int shij = 0;
	for(int j = i-1;j >= 1;j--){
		shij += w[j]*pow(2,j-1);
	}
	return shij;
}
int wxor(int a,int d){
	int p[10000];
	int c = 1;
	while(a != 0){
		int b = a%10;
		a = a/10;
		p[c] = b;
		c++;
	}
	int o[10000];
	int e = 1;
	while(d != 0){
		int b = d%10;
		d = d/10;
		o[e] = b;
		e++;
	}
	int size = max(c,e);
	int l[10000];
	for(int i = 1;i <= size-1;i++){
		if(p[i] != o[i]){
			l[i] = 1;
		}
		else{
			l[i] = 0;
		}
	}
	int jg = 0;
	for(int i = size-1;i >= 1;i--){
		jg += l[i]*pow(10,i-1);
	}
	return jg;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int op[60000];
	int n,k;
	cin >> n >> k;
	int s;
	for(int  i = 1;i <= n;i++){
		cin >> s;
		op[i] = er(s);
	}
	int ans = 0;
	for(int i = 1;i <= n;i++){
		for (int j =i;j <= n;j++){
			int lk = j-i;
			int mk =0;
			if (lk == 0){
				mk = shi(wxor(op[i],op[i]));
			}
			else{
				for (int k = 1;k <= lk+1;k++){
					int mk1 = wxor(op[i+k-1],op[i+k]);
					mk += shi(mk1);
				}
			}	
			if(mk==k){
				ans = max(ans,j-i+1);
			}
		}
	}
	cout << ans;
	return 0;
}
