#include<bits/stdc++.h>
int qpow(int n,size_t k){
	int ans=1;
	while(k!=0){
		ans*=n;
		k--;
	}
	return ans;
}
std::vector<int> zh(int x){
    std::vector<int> ans;
    while(x!=0){
        ans.push_back(x%2);
        x/=2;
    }
    return ans;
}
int fzh(std::vector<int> a){
	int ans=0;
	for(size_t i=0;i<a.size();i++){
		if(a[i]==0) continue;
		ans+=qpow(2,i);
	}
	return ans;
}
std::vector<int> yh(std::vector<int> a,std::vector<int> b){
    int ml=std::max(a.size(),b.size());
    a.resize(ml);
    b.resize(ml);
    std::vector<int> ans;
    ans.resize(ml);
    for(int i=0;i<ml;i++){
        if(a[i]!=b[i]) ans[i]++;
    }
    return ans;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    int n,a[500010],k;
    std::scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        std::scanf("%d",&a[i]);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        
        std::vector<int> nowh=zh(a[i]);
        for(int d=i;d<=n;d++){
            if(fzh(nowh)==k){
                ans++;
                i=d;
                break;
            }
            if(fzh(nowh)>k){
                i=d;
                break;
            }
            nowh=yh(nowh, zh(a[d]) );
            //std::printf("st:%d end:%d %d %d\n",i,to,d,fzh(nowh));
        }
        
        
    }
    std::cout<<ans;
    return 0;
}
