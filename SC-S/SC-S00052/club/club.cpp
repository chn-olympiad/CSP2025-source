#include <iostream>
#include <algorithm>

const int MAX = 1e5+5;

bool flagA = true;
long long n,t,sum = 0;
long long cnt[5];

struct person{
	int d[5];
};
person a[MAX];

bool cmp(const person& A,const person& B){
	if(A.d[0] != B.d[0])	return A.d[0] > B.d[0];
	if(A.d[1] != B.d[1])	return A.d[1] > B.d[1];
	return A.d[2] > B.d[2];
}

void dfs(long long step,long long s){
    if(step == n){
        sum = std::max(sum,s);
        return;
    }

    for(int i = 0;i < 3;++i){
    	++cnt[i];
    	
        if(cnt[i] <= n/2)	dfs(step+1,s+a[step].d[i]);
		
		--cnt[i];
    }

    return;
}

void f(){
	long long temp[MAX];
	for(int i=0;i < n;++i)	temp[i] = a[i].d[0];
	
	std::sort(temp,temp+n);
	
	for(int i = 1;i <= n/2;++i)	sum += temp[i];
	
	return;
}

int main()
{
	freopen("club.in","r",stdin); 
	freopen("club.out","w",stdout); 
	
	std::cin >> t;
	while(t--){
		sum = 0;
		cnt[0] = cnt[1] = cnt[2] = 0;
		
	    std::cin >> n;
	    for(int i=0;i < n;++i){
	        std::cin >> a[i].d[0] >> a[i].d[1] >> a[i].d[2];
	        if(a[i].d[2] != 0 || a[i].d[1] != 0)	flagA = false;
		}
		
		if(n <= 10)	dfs(0,0);
		else if(flagA)	f();
		
		std::cout << sum << std::endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	
    return 0;
}
