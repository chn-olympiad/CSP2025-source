#include<bits/stdc++.h>
using namespace std;
int c1[10005];
int c2[10005];
int c3[10005];
bool cmp(int q,int w){
	return q > w;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t = 0;
	scanf("%d",&t);
	while(t--){
		int n = 0, cnt = 0;
		scanf("%d",&n);
		if(n == 2){
			int a1 = 0,a2 = 0,b1 = 0,b2 = 0,c1 = 0,c2 = 0;
			cin >> a1 >> b1 >> c1;
			cin >> a2 >> b2 >> c2;	
			int f = max(a1+b2,a1+c2);
			int s = max(b1+a2,b1+c2);
			int h = max(c1+b2,c1+a2);
			cnt = max(h,max(f,s));
			printf("%d\n",cnt);
		}else{
			int c = n/2;
			for(int i = 0; i < n; i++){
				scanf("%d%d%d",&c1[i],&c2[i],&c3[i]);
			}
			sort(c1+0,c1+n,cmp);
			sort(c2+0,c2+n,cmp);
			sort(c3+0,c3+n,cmp);
			int i1 = 0, i2 = 0, i3 = 0;
			while(n--){
				int max_1 = c1[i1];
				int max_2 = c2[i2];
				int max_3 = c3[i3];
				if(max_1>=max_2 && max_1>=max_3 && i1<c){
					cnt += max_1;
					i1++;
				}else if(max_2>=max_1 && max_2>=max_3 && i2<c){
					cnt += max_2;
					i2++;
				}else if(max_3>=max_2 && max_3>=max_1 && i3<c){
					cnt += max_3;
					i3++;
				}
			}
			printf("%d\n",cnt);
		}
	}
	return 0;
}

