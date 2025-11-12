#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		a[i]=114514;
		if(s[i]>='0'&&s[i]<='9'){
			if(s[i]<='5'){
				if(s[i]=='5'){
					a[i]=5;
					continue;
				}
				else{
					if(s[i]<='3'){
						if(s[i]=='3'){
							a[i]=3;
							continue;
						}
						else{
							if(s[i]>='1'){
								if(s[i]=='1'){
									a[i]=1;
									continue;
								}
								else{
									if(s[i]=='2'){
										a[i]=2;
										continue;
									}
								}
							}
							else{
								if(s[i]=='0'){
									a[i]=0;
									continue;
								}
							}
						}
					}
					else{
						if(s[i]=='4'){
							a[i]=4;
							continue;
						}
					}
				}
			}
			else{
				if(s[i]>='8'){
					if(s[i]=='8'){
						a[i]=8;
						continue;
					}
					else {
						if(s[i]=='9'){
							a[i]=9;
							continue;
						}
					}
				}
				else{
					if(s[i]=='7'){
						a[i]=7;
						continue;
					}
					else{
						if(s[i]=='6'){
							a[i]=6;
							continue;
						}
					}
				}
			}
		}
	}
	int sum=s.size();
	sort(a,a+sum,cmp);
	for(int i=0;i<s.size();i++){
		if(a[i]!=114514) printf("%d",a[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
