#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	long long p[250000],cnt=0,op=0;
	char a='1',b='2',c='3',d='4',e='5',f='6',g='7',h='8',i='9',j='0';
	cin>>s;
	for(int m=0; m<=s.size()-1; m++) {
		if(s[m]==a) {
			p[cnt]=1;
			cnt=cnt+1;
		} else {
			if(s[m]==b) {
				p[cnt]=2;
				cnt=cnt+1;
			} else {
				if(s[m]==c) {
					p[cnt]=3;
					cnt=cnt+1;
				} else {
					if(s[m]==d) {
						p[cnt]=4;
						cnt=cnt+1;
					} else {
						if(s[m]==e) {
							p[cnt]=5;
							cnt=cnt+1;
						} else {
							if(s[m]==f) {
								p[cnt]=6;
								cnt=cnt+1;
							} else {
								if(s[m]==g) {
									p[cnt]=7;
									cnt=cnt+1;
								} else {
									if(s[m]==h) {
										p[cnt]=8;
										cnt=cnt+1;
									} else {
										if(s[m]==i) {
											p[cnt]=9;
											cnt=cnt+1;
										} else {
											if(s[m]==j) {
												p[cnt]=0;
												cnt=cnt+1;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for(long long m=0; m<=cnt-1; m++) {
		for(long long n=1; n<=cnt-1; n++) {
			if(p[n-1]<p[n]) {
				swap(p[n],p[n-1]);
			}
		}
	}
	for(int m=0; m<=s.size()-1; m++) {
		if(p[m]==1) {
			cout<<"1";
		} else {
			if(p[m]==2) {
				cout<<"2";
			} else {
				if(p[m]==3) {
					cout<<"3";
				} else {
					if(p[m]==4) {
					cout<<"4";
				} 
					else {
						if(p[m]==5) {
							cout<<"5";
						} else {
							if(p[m]==6) {
								cout<<"6";
							} else {
								if(p[m]==7) {
									cout<<"7";
								} else {
									if(p[m]==8) {
										cout<<"8";
									} else {
										if(p[m]==9) {
											cout<<"9";
										} else {
											if(p[m]==0) {
												cout<<"0";
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return 0;
}
