#include <bits/stdc++.h>
using namespace std;

int tt,n,temp;
long long ga=0,gb=0,gc=0;
long long dp[1000005][4];
char ch[3];
char operations[100005];
int h=1;

struct node{
	long long a;
	long long b;
	long long c;
	long long sum;
}a[10000005];


inline bool cmp(node var1,node var2){
	return var1.sum > var2.sum;
}

inline int get(int i,int j){
	long long o;
	switch(j){
		case 1:{
			o=a[i].a;
			break;
		}
		case 2:{
			o=a[i].b;
			break;
		}
		case 3:{
			o=a[i].c;
			break;
		}
//		default:{
//			o=0;
//			break;
//		}
	}
	return o;
}

inline int getMax(int i){
	if (dp[i][1] >= dp[i][2] && dp[i][1] >= dp[i][3]){
		return 1;
	}
	if (dp[i][2] >= dp[i][1] && dp[i][2] >= dp[i][3]){
		return 2;
	}
	return 3;
}

inline void add(int x){
	operations[h]=ch[x];
	h++;
	switch(ch[x]){
		case 'a':{
			ga++;
			break;
		}
		case 'b':{
			gb++;
			break;
		}
		case 'c':{
			gc++;
			break;
		}
	}
	return;
}

inline int getSum(){
	int cnt = 0;
	for (int i =1 ; i<= n ; i ++ ){
		cout << operations[i] << " ";
		switch(operations[i]){
			case 'a':{
				cnt += a[i].a;
				break;
			}
			case 'b':{
				cnt += a[i].b;
				break;
			}
			case 'c':{
				cnt += a[i].c;
				break;
			}
		}
	}
	return cnt;
}

inline void init(){
	cin >> n;
	temp = n/2;
	memset(a,0,sizeof a);
	memset(ch,'n',sizeof ch);
	memset(operations,'n',sizeof operations);
	ga=0;gb=0;gc=0;
	h=1;
	memset(dp,0,sizeof dp);
	for (long long j = 1 ; j <= n; j ++ ){
		cin >> a[j].a >> a[j].b >> a[j].c;
		a[j].sum = a[j].a+a[j].b+a[j].c;
	}
	sort(a+1,a+n+1,cmp);
	return;
}

inline long long calculate(){
	for (long long i =1 ; i <= n ; i ++ ){
		for (long long j = 1;j<=3;j++){
			dp[i][j]=get(i,j);
			long long m = dp[i-1][1];
			long long k = dp[i-1][2];
			long long q = dp[i-1][3];
			long long p=0;
			
			if(ga<temp){
				if(gb<temp){
					if(gc<temp){
						p=max(max(m,k),q);
						
						if (m>=k && m >= q){
							ch[j] = 'a';
						}
						else if(k >= m && k >= q){
							ch[j]='b';
						}
						else if(q>=m && q >=k){
							ch[j] = 'c';
						}
					}
					else{
						p=max(m,k);
						if (m>=k){
							ch[j]='a';
						}
						else{
							ch[j] ='b';
						}
					}
				}
				else{
					p=m;
					ch[j]='a';
				}
			}
			else if(gb<temp){
				if (gc < temp)
				{
					p=max(k,q);
					
					if(k>=q)
					{
						ch[j]='b';
					}
					else{
						ch[j]='c';
					}
				}
				else{
					p=k;
					ch[j]='b';
				}
			}
			else{
				p=q;
				ch[j]='c';
			}
			
			dp[i][j]+=p;
			//cout << dp[i][j] << endl;
		}
		if (i!=1){
			switch(getMax(i)){
			case 1:{

				add(1);
				break;
			}
			case 2:{
	
				add(2);
				break;
			}
			case 3:{
			
				add(3);
				break;
			}
		}
		}
		else{
			ch[1]='a';
			ch[2]='b';
			ch[3]='c';

	switch(getMax(1)){
			case 1:{

				add(1);
				break;
			}
			case 2:{

				add(2);
				break;
			}
			case 3:{
				add(3);

				break;
			}
		}
		}
		
		
	

	//	cout << dp[i][1] << " " << dp[i][2] << " " << dp[i][3]<<endl;
	//	cout <<  ga << " " << gb << " " << gc << endl;
	}
	//return getSum();
	return max(max(dp[n][1],dp[n][2]),dp[n][3]);
	
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> tt;

	while(tt--){

		init();
//		for (int f = 1 ; f <= n;f  ++ ){
//				cout << a[f].a << a[f].b << a[f].c << endl;
//		}
		cout << calculate() << endl;
	}
	
	return 0;
}
