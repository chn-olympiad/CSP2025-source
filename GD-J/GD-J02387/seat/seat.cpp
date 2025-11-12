#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int f = 0,k = 0;
	char c = getchar();
	while(!isdigit(c)){
		f |= c == '-';
		c = getchar();
	}
	while(isdigit(c)){
		k = k * 10 + c - '0';
		c = getchar();
	}
	return f ? -k : k;
}
int n,m;
struct stu{
	int id,v;
	friend bool operator < (stu a,stu b){
		return a.v > b.v;
	}
}a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n = read(),m = read();
	for(int i = 1;i <= n * m;i++){
		a[i].v = read(),a[i].id = i;
	}
	sort(a + 1,a + 1 + n * m);
	int to = 0,cur = 1,i = 1,j = 1;//第i列第j行 
	//to为0是朝下 
	while(1){
		if(a[cur].id == 1){
			break;
		}
		if(!to){
			++j;
			if(j > n){
				++i;
				j = n;
				to = 1;
			}
		}
		else {
			--j;
			if(j < 1){
				++i;
				j = 1;
				to = 0;
			}
		}
		++cur;
	}
	printf("%lld %lld",i,j);
	return 0;
}
