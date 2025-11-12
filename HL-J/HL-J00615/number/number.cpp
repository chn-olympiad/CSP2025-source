#include<bits/stdc++.h>
using namespace std;

char s_[1000011];
int n_[1000011], len_n = 1;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",&s_);
	for (int i = 0; i <= strlen(s_) - 1; i++){
		if (s_[i] - '0' >= 0 && s_[i] - '0' <= 9){
			n_[len_n] = s_[i] - '0';
			len_n++;
		}
	}
	for (int i = 1; i <= len_n - 2; i++){
		int max_n = n_[i],max_n_where;
		for (int j = i; j <= len_n - 1; j++)
			if (n_[j] >= max_n){
				max_n = n_[j];
				max_n_where = j;
			}
		int t = n_[i];
		n_[i] = max_n;
		n_[max_n_where] = t;
	}
	for (int i = 1; i <= len_n - 1; i++)
		printf("%d", n_[i]);
	return 0;
} 
