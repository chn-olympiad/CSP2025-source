#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>

using namespace std;

int n, k, jsq = 0, sum = 0, s[1005][1005], a[500005];
bool oo = true, oo2 = true;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		if(oo && a[i] != 1 && a[i] != 0) oo = false;
		else if(oo && a[i] == 1) jsq++;
		
		a[0] = a[1];
		if(oo2 && a[i] != a[i - 1]) oo2 = false;
	}
	
	if(oo2 && k == 0){
		int o = ceil(n * 1.0 / 2);
		printf("%d", o);
		
		fclose(stdin);
		fclose(stdout);
		
		return 0;
	}
	
	a[0] = 0;
	if(oo){
		if(k == 1){
			printf("%d", jsq);
		}else{
			int cs = 0, noo = n - jsq;
			for(int i = 1; i <= n; i++){
				if(a[i] == a[i - 1] && a[i] == 1) cs++;
				else noo += (cs + 1) / 2, cs = 0;
			}
			
			printf("%d", noo);
		}
		
		fclose(stdin);
		fclose(stdout);
		
		return 0;
	}
	
	memset(s, -1, sizeof(s));
	
	for(int i = 1; i <= n; i++){
		s[i][i] = a[i];
		for(int j = i + 1; j <= n; j++){
			s[i][j] = s[i][j - 1] xor a[j];
		}
	}
	
	for(int e = 1; e <= n - 1; e++)
	for(int i = 1; i <= n; i++)
		for(int j = i;j <= i + e && j <= n; j++)
			if(s[i][j] == -1) continue;
			else if(s[i][j] == k){
				bool no = false;
				for(int x = i; x <= j; x++)
					if(a[x] == -1){
						no = true;
						break;
					}
				if(no) continue;
				
				sum++;
				for(int x = i; x <= j; x++){
					a[x] = -1;
				}
			}
	
	printf("%d", sum);
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
/*
2 1 0 3
*/
