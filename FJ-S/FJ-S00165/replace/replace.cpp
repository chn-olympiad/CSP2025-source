#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int data1[n];
	int data2[n];
	int data3[n];
	for (int i = 0;i<n;i++) {
		for (int j =0;;j++) {
			char c = getchar();
			if (c == ' ') {
				data2[i] = j;
				break;
			}
			if (c=='b') {
				data1[i] = j;
			}
			
		}
		for (int j =0;;j++) {
			char c = getchar();
			if (c == '\n') {
				break;
			}
			if (c=='b') {
				data3[i] = data1[i]-j;
			}
		}
	}
	for (int i =0;i<m;i++) {
		int length = 0;
		int qa = 0;
		int cha = 0;
		for (int j =0;;j++) {
			char c = getchar();
			if (c == ' ') {
				length = j;
				break;
			}
			if (c=='b') {
				qa = j;
			}
		}
		for (int j =0;;j++) {
			char c = getchar();
			if (c == '\n') {
				break;
			}
			if (c=='b') {
				cha = qa-j;
			}
		}
		int ans = 0;
		for (int j = 0;j<n;j++) {
			if (data2[j] > length ) {
				continue;
			}
			if (data1[j] > qa) {
				continue;
			}
			if (data2[j] - data1[j] > length-qa) {
				continue;
			}
			if (data3[j] == cha) {
				ans++;
			}
		}
		printf("%d\n",ans);
	}
}
