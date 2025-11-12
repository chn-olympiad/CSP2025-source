#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,ans;
const ll MAXN=5e3+10;
const ll MOD=998244353;
int aa[MAXN];

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) cin>>aa[i];
	sort(aa+1,aa+n+1);
	for(int a=1; a<=n; a++) {
		for(int b=2; b<=n&&b!=a; b++) {
			for(int c=3; c<=n&&c!=a&&c!=b; c++) {
				if(aa[a]+aa[b]+aa[c]>2*(max(aa[a],max(aa[b],aa[c])))) {
					ans++;
					ans%=MOD;
				}
			}
		}
	}//3
	for(int a=1; a<=n; a++) {
		for(int b=2; b<=n&&b!=a; b++) {
			for(int c=3; c<=n&&c!=a&&c!=b; c++) {
				for(int d=4; d<=n&&d!=a&&d!=b&&d!=c; d++) {
					if(aa[a]+aa[b]+aa[c]+aa[d]>2*(max(aa[a],max(aa[b],max(aa[c],aa[d]))))) {
						ans++;
						ans%=MOD;
					}
				}
			}
		}
	}//4
	//cout<<ans;
	for(int a=1; a<=n; a++) {
		for(int b=2; b<=n&&b!=a; b++) {
			for(int c=3; c<=n&&b!=c&&c!=a; c++) {
				for(int d=4; d<=n&&d!=a&&b!=d&&d!=c; d++) {
					for(int e=5; e<=n&&e!=a&&b!=e&&c!=e&&e!=d; e++) {
						if(aa[a]+aa[b]+aa[c]+aa[d]+aa[e]>2*(max(aa[a],max(aa[b],max(aa[c],max(aa[d],aa[e])))))) {
							ans++;
							//cout<<a<<' '<<b<<' '<<c<<' '<<d<<' '<<e<<'\n';
							ans%=MOD;
						}
					}
				}

			}
		}
	}//5
	for(int a=1; a<=n; a++) {
		for(int b=2; b<=n&&b!=a; b++) {
			for(int c=3; c<=n&&b!=c&&c!=a; c++) {
				for(int d=4; d<=n&&d!=a&&b!=d&&d!=c; d++) {
					for(int e=5; e<=n&&e!=a&&b!=e&&c!=e&&e!=d; e++) {
						for(int f=6; f<=n&&f!=a&&b!=f&&c!=f&&f!=d&&f!=e; f++)
							if(aa[a]+aa[b]+aa[c]+aa[d]+aa[e]+aa[f]>2*(max(aa[a],max(aa[b],max(aa[c],max(aa[d],max(aa[e],aa[f]))))))) {
								ans++;
								//cout<<a<<' '<<b<<' '<<c<<' '<<d<<' '<<e<<'\n';
								ans%=MOD;
							}
					}
				}

			}
		}
	}//6
	for(int a=1; a<=n; a++) {
		for(int b=2; b<=n&&b!=a; b++) {
			for(int c=3; c<=n&&b!=c&&c!=a; c++) {
				for(int d=4; d<=n&&d!=a&&b!=d&&d!=c; d++) {
					for(int e=5; e<=n&&e!=a&&b!=e&&c!=e&&e!=d; e++) {
						for(int f=6; f<=n&&f!=a&&b!=f&&c!=f&&f!=d&&f!=e; f++) {
							for(int g=7; g<=n&&g!=a&&b!=g&&c!=g&&g!=d&&g!=e&&g!=f; g++) {
								if(aa[a]+aa[b]+aa[c]+aa[d]+aa[e]+aa[f]+aa[g]>2*(max(aa[a],max(aa[b],max(aa[c],max(aa[d],max(aa[e],max(aa[f],aa[g])))))))) {
									ans++;
									//cout<<a<<' '<<b<<' '<<c<<' '<<d<<' '<<e<<'\n';
									ans%=MOD;
								}
							}
						}

					}
				}

			}
		}
	}//7
	for(int a=1; a<=n; a++) {
		for(int b=2; b<=n&&b!=a; b++) {
			for(int c=3; c<=n&&b!=c&&c!=a; c++) {
				for(int d=4; d<=n&&d!=a&&b!=d&&d!=c; d++) {
					for(int e=5; e<=n&&e!=a&&b!=e&&c!=e&&e!=d; e++) {
						for(int f=6; f<=n&&f!=a&&b!=f&&c!=f&&f!=d&&f!=e; f++) {
							for(int g=7; g<=n&&g!=a&&b!=g&&c!=g&&g!=d&&g!=e&&g!=f; g++) {
								for(int h=8; h<=n&&h!=a&&h!=b&&c!=h&&h!=d&&h!=e&&h!=f&&h!=g; h++) {
									if(aa[a]+aa[b]+aa[c]+aa[d]+aa[e]+aa[f]+aa[g]+aa[h]>2*(max(aa[a],max(aa[b],max(aa[c],max(aa[d],max(aa[e],max(aa[f],max(aa[g],aa[h]))))))))) {
										ans++;
										//cout<<a<<' '<<b<<' '<<c<<' '<<d<<' '<<e<<'\n';
										ans%=MOD;
									}
								}
							}
						}

					}
				}

			}
		}
	}//8
	for(int a=1; a<=n; a++) {
		for(int b=2; b<=n&&b!=a; b++) {
			for(int c=3; c<=n&&b!=c&&c!=a; c++) {
				for(int d=4; d<=n&&d!=a&&b!=d&&d!=c; d++) {
					for(int e=5; e<=n&&e!=a&&b!=e&&c!=e&&e!=d; e++) {
						for(int f=6; f<=n&&f!=a&&b!=f&&c!=f&&f!=d&&f!=e; f++) {
							for(int g=7; g<=n&&g!=a&&b!=g&&c!=g&&g!=d&&g!=e&&g!=f; g++) {
								for(int h=8; h<=n&&h!=a&&b!=h&&c!=h&&h!=d&&h!=e&&h!=f&&h!=g; h++) {
									for(int i=9; i<=n&&i!=a&&b!=i&&c!=i&&i!=d&&i!=e&&i!=f&&i!=g&&i!=h; i++) {
										if(aa[a]+aa[b]+aa[c]+aa[d]+aa[e]+aa[f]+aa[g]+aa[h]+aa[i]>2*(max(aa[a],max(aa[b],max(aa[c],max(aa[d],max(aa[e],max(aa[f],max(aa[g],max(aa[h],aa[i])))))))))) {
											ans++;
											//cout<<a<<' '<<b<<' '<<c<<' '<<d<<' '<<e<<'\n';
											ans%=MOD;
										}
									}
								}
							}
						}

					}
				}

			}
		}
	}//9
	for(int a=1; a<=n; a++) {
		for(int b=2; b<=n&&b!=a; b++) {
			for(int c=3; c<=n&&b!=c&&c!=a; c++) {
				for(int d=4; d<=n&&d!=a&&b!=d&&d!=c; d++) {
					for(int e=5; e<=n&&e!=a&&b!=e&&c!=e&&e!=d; e++) {
						for(int f=6; f<=n&&f!=a&&b!=f&&c!=f&&f!=d&&f!=e; f++) {
							for(int g=7; g<=n&&g!=a&&b!=g&&c!=g&&g!=d&&g!=e&&g!=f; g++) {
								for(int h=8; h<=n&&h!=a&&b!=h&&c!=h&&h!=d&&h!=e&&h!=f&&h!=g; h++) {
									for(int i=9; i<=n&&i!=a&&b!=i&&c!=i&&i!=d&&i!=e&&i!=f&&i!=g&&i!=h; i++) {
										for(int j=10; j<=n&&j!=a&&b!=j&&c!=j&&j!=d&&j!=e&&j!=f&&j!=g&&j!=h&&j!=i; j++) {
											if(aa[a]+aa[b]+aa[c]+aa[d]+aa[e]+aa[f]+aa[g]+aa[h]+aa[i]+aa[j]>2*(max(aa[a],max(aa[b],max(aa[c],max(aa[d],max(aa[e],max(aa[f],max(aa[g],max(aa[h],max(aa[i],aa[j]))))))))))) {
												ans++;
												//cout<<a<<' '<<b<<' '<<c<<' '<<d<<' '<<e<<'\n';
												ans%=MOD;
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
	}//10
	cout<<ans;
	return 0;
}
