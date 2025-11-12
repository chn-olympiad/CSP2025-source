#include<bits/stdc++.h>
int main()
{
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    std::string s;
    std::cin>>s;
    long long a[10]={0};
    for(size_t i=0;i<s.size();i++){
        a[ s[i]-'0' ]++;
    }
    for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			std::printf("%d",i);
		}
	}
    return 0;
}
