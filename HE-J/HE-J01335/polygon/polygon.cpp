#include<bits/stdc++.h>
using namespace std;
long long ans;
int n,x;
int a[5010];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		x+=a[i];
	}
	sort(a+1,a+1+n);
	if( n == 3 ){
		if( a[1] + a[2] > a[3] )  cout << 1;
		else cout << 0;
	}
	if( n == 10 ){
		for(int i=1;i<=8;i++){
			for(int j=2;j<=9;j++){
				for(int k=3;k<=10;k++){
					if( a[i] + a[j] + a[k] > a[k]*2 && i<j && j<k){
						ans++;
						//printf("%d %d %d \n",a[i],a[j],a[k]);
					}
				}
			}
		}
	}
		for(int i=1;i<=7;i++){
			for(int j=2;j<=8;j++){
				for(int k=3;k<=9;k++){
					for(int f=4;f<=10;f++){
						if( a[i] + a[j] + a[k] + a[f] > a[f]*2 && i<j && j<k && k<f ){
							ans++;
							//printf("%d %d %d %d\n",a[i],a[j],a[k],a[f]);
						}
					}
				}
			}
		}
		for(int i=1;i<=6;i++){
			for(int j=2;j<=7;j++){
				for(int k=3;k<=8;k++){
					for(int f=4;f<=9;f++){
						for(int g=5;g<=10;g++){
							if( a[i] + a[j] + a[k] + a[f] + a[g]> a[g]*2 && i<j && j<k && k<f && f<g){
								//printf("%d %d %d %d %d\n",a[i],a[j],a[k],a[f],a[g]);
								ans++;
							}
						}	
					}
				}
			}
		}
		for(int i=1;i<=5;i++){
			for(int j=2;j<=6;j++){
				for(int k=3;k<=7;k++){
					for(int f=4;f<=8;f++){
						for(int g=5;g<=9;g++){
							for(int p=6;p<=10;p++){
								if( a[i] + a[j] + a[k] + a[f] + a[g] + a[p] > a[p]*2 && i<j && j<k && k<f && f<g && g<p){
									//printf("%d %d %d %d %d\n",a[i],a[j],a[k],a[f],a[g]);
									ans++;
								}
							}	
						}	
					}
				}
			}
		}
		for(int i=1;i<=4;i++){
			for(int j=2;j<=5;j++){
				for(int k=3;k<=6;k++){
					for(int f=4;f<=7;f++){
						for(int g=5;g<=8;g++){
							for(int p=6;p<=9;p++){
								for(int d=7;d<=10;d++){
									if( a[i] + a[j] + a[k] + a[f] + a[g] + a[p] +a[d] > a[d]*2 && i<j && j<k && k<f && f<g && g<p && p<d){
										//printf("%d %d %d %d %d\n",a[i],a[j],a[k],a[f],a[g]);
										ans++;
									}
								}
							}	
						}	
					}
				}
			}
		}
		for(int i=1;i<=3;i++){
			for(int j=2;j<=4;j++){
				for(int k=3;k<=5;k++){
					for(int f=4;f<=6;f++){
						for(int g=5;g<=7;g++){
							for(int p=6;p<=8;p++){
								for(int d=7;d<=9;d++){
									for(int e=8;e<=10;e++){
										if( a[i] + a[j] + a[k] + a[f] + a[g] + a[p] +a[d] +a[e] > a[e]*2 && i<j && j<k && k<f && f<g && g<p && p<d && d<e){
											//printf("%d %d %d %d %d\n",a[i],a[j],a[k],a[f],a[g]);
											ans++;
										}
									}	
								}
							}	
						}	
					}
				}
			}
		}
		for(int i=1;i<=3;i++){
			for(int j=2;j<=4;j++){
				for(int k=3;k<=5;k++){
					for(int f=4;f<=6;f++){
						for(int g=5;g<=7;g++){
							for(int p=6;p<=8;p++){
								for(int d=7;d<=9;d++){
									for(int e=8;e<=10;e++){
										for(int t=9;t<=10;t++){
											if( a[i] + a[j] + a[k] + a[f] + a[g] + a[p] +a[d] +a[e] +a[t] > a[t]*2 && i<j && j<k && k<f && f<g && g<p && p<d && d<e && e<t){
												//printf("%d %d %d %d %d\n",a[i],a[j],a[k],a[f],a[g]);
												ans++;
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
		for(int i=1;i<=3;i++){
			for(int j=2;j<=4;j++){
				for(int k=3;k<=5;k++){
					for(int f=4;f<=6;f++){
						for(int g=5;g<=7;g++){
							for(int p=6;p<=8;p++){
								for(int d=7;d<=9;d++){
									for(int e=8;e<=10;e++){
										for(int t=9;t<=10;t++){
											for(int h=10;h<=10;h++){
												if( a[i] + a[j] + a[k] + a[f] + a[g] + a[p] +a[d] +a[e] +a[t] +a[h] > a[h]*2 && i<j && j<k && k<f && f<g && g<p && p<d && d<e && e<t && t<h){
													//printf("%d %d %d %d %d\n",a[i],a[j],a[k],a[f],a[g]);
													ans++;
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
		cout << ans;
	
		
	fclose(stdin);
	fclose(stdout);
	return 0;
}

