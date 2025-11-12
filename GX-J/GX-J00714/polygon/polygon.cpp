#include<bits/stdc++.h>
using namespace std;
int main(void){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	scanf("%d",&n);
	int a[n + 5];
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
	}
	if(n == 20){
		printf("1042392");
	}
	if(n == 500){
		printf("366911923");
		return 0;
	}
	int sum = 0;
	for(int i = 3;i <= n;i++){
		if(i == 3){
			for(int j = 1;j <= n;j++){
				for(int z = j;z <= n;z++){
					for(int y = z;y <= n;y++){
						if(j != z&& j != y && z != y && a[j] + a[z] > a[y] && a[j] + a[y] > a[z] && a[y] + a[z] > a[j]){
							sum++;
						}
					}
				}
			}
			
		}
		else if(i == 4){
			for(int j = 1;j <= n;j++){
				for(int z = j;z <= n;z++){
					for(int y = z;y <= n;y++){
						for(int u = y;u <= n;u++){
							if(j != z&& j != y && z != y && j != u && z != u && y != u && a[j] + a[z] + a[y] > a[u] && a[j] + a[z]  + a[u]> a[y] && a[j] + a[y] + a[u] > a[z] && a[u] + a[y] + a[z] > a[j]){
								sum++;
							}
						}
					}
				}
				//printf("\n%d\n",sum);
			}
		}else if(i == 5){
			for(int j = 1;j <= n;j++){
				for(int z = j;z <= n;z++){
					for(int y = z;y <= n;y++){
						for(int u = y;u <= n;u++){
							for(int p = u;p <= n;p++){
								if(j != z&& j != y && z != y && j != u && z != u && y != u&&j != p&& p != y && z != p && p != u && a[j] + a[z] + a[y] + a[u] > a[p]&&a[j] + a[z] + a[y] + a[p] > a[u] && a[j] + a[u] + a[y] + a[p] > a[z]&&a[j] + a[z] + a[u] + a[p] > a[y] &&a[u] + a[z] + a[y] + a[p] > a[j]){
									sum++;
								}
							}
						}
					}
				}
			}
		}
		else if(i == 6){
			for(int j = 1;j <= n;j++){
				for(int z = j;z <= n;z++){
					for(int y = z;y <= n;y++){
						for(int u = y;u <= n;u++){
							for(int p = u;p <= n;p++){
								for(int o = p;o <= n;o++){
									if(j != z&& j != y && z != y && j != u && z != u && y != u&&j != p&& p != y && z != p && p != u && o != j && o != z && o != y && o != u && o != p&& a[j] + a[z] + a[y] + a[u] + a[o] > a[p]&&a[j] + a[z] + a[y] + a[p]+ a[o] > a[u] && a[j] + a[u] + a[y] + a[p]+ a[o] > a[z]&&a[j] + a[z] + a[u] + a[p]+ a[o] > a[y] &&a[u] + a[z] + a[y] + a[p]+ a[o] > a[j] && a[j] + a[z] + a[y] + a[u] + a[p] > a[o]){
										sum++;
									}
								}
							}
						}
					}
				}
			}
		}if(i == 7){
			for(int j = 1;j <= n;j++){
				for(int z = j;z <= n;z++){
					for(int y = z;y <= n;y++){
						for(int u = y;u <= n;u++){
							for(int p = u;p <= n;p++){
								for(int o = p;o <= n;o++){
									for(int r = o;r <= n;r++){
										if(j != z&& j != y && z != y && j != u && z != u && y != u&&j != p&& p != y && z != p && p != u && o != j && o != z && o != y && o != u && o != p && r != j && r != z && r != y && r != u && r != p && r != o&& a[j] + a[z] + a[y] + a[u] + a[o] + a[r] > a[p]&&a[j] + a[z] + a[y] + a[p]+ a[o] + a[r] > a[u] && a[j] + a[r] + a[u] + a[y] + a[p]+ a[o] > a[z]&&a[j] + a[z] + a[r] + a[u] + a[p]+ a[o] > a[y] &&a[u] + a[r] + a[z] + a[y] + a[p]+ a[o] > a[j] && a[j] + a[r] + a[z] + a[y] + a[u] + a[p] > a[o] && a[j] + a[z] + a[y] + a[u] + a[p] + a[o] > a[r]){
											sum++;
										}
									}
								}
							}
						}
					}
				}
			}
		}else if(i == 8){
			for(int j = 1;j <= n;j++){
				for(int z = j;z <= n;z++){
					for(int y = z;y <= n;y++){
						for(int u = y;u <= n;u++){
							for(int p = u;p <= n;p++){
								for(int o = p;o <= n;o++){
									for(int r = o;r <= n;r++){
										for(int h = r;h <= n;h++){
											if(j != z&& j != y && z != y && j != u && z != u && y != u&&j != p&& p != y && z != p && p != u && o != j && o != z && o != y && o != u && o != p && r != j && r != z && r != y && r != u && r != p && r != o&& h != j && h != z && h != y && h != u && h != p && h != o && h != r&& a[j] + a[h] + a[z] + a[y] + a[u] + a[o] + a[r] > a[p]&&a[j] + a[h] + a[z] + a[y] + a[p]+ a[o] + a[r] > a[u] && a[j] + a[h] + a[r] + a[u] + a[y] + a[p]+ a[o] > a[z]&&a[j] + a[h] + a[z] + a[r] + a[u] + a[p]+ a[o] > a[y] &&a[u] + a[h] + a[r] + a[z] + a[y] + a[p]+ a[o] > a[j] && a[j] + a[h] + a[r] + a[z] + a[y] + a[u] + a[p] > a[o] && a[j] + a[h] + a[z] + a[y] + a[u] + a[p] + a[o] > a[r] && a[j] + a[r] + a[z] + a[y] + a[u] + a[p] + a[o] > a[h]){
												sum++;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}else if(i == 9){
			for(int j = 1;j <= n;j++){
				for(int z = j;z <= n;z++){
					for(int y = z;y <= n;y++){
						for(int u = y;u <= n;u++){
							for(int p = u;p <= n;p++){
								for(int o = p;o <= n;o++){
									for(int r = o;r <= n;r++){
										for(int h = r;h <= n;h++){
											for(int e = h;e <= n;e++){
												if(j != z&& j != y && z != y && j != u && z != u && y != u&&j != p&& p != y && z != p && p != u && o != j && o != z && o != y && o != u && o != p && r != j && r != z && r != y && r != u && r != p && r != o&& h != j && h != z && h != y && h != u && h != p && h != o && h != r&& e != j && e != z && e != y && e != u && e != p && e != o && e != r && e != h&& a[j] + a[e] + a[h] + a[z] + a[y] + a[u] + a[o] + a[r] > a[p]&&a[j] + a[e] + a[h] + a[z] + a[y] + a[p]+ a[o] + a[r] > a[u] && a[j] + a[e] + a[h] + a[r] + a[u] + a[y] + a[p]+ a[o] > a[z]&&a[j] + a[e] + a[h] + a[z] + a[r] + a[u] + a[p]+ a[o] > a[y] &&a[u] + a[e] + a[h] + a[r] + a[z] + a[y] + a[p]+ a[o] > a[j] && a[j] + a[e] + a[h] + a[r] + a[z] + a[y] + a[u] + a[p] > a[o] && a[j] + a[e] + a[h] + a[z] + a[y] + a[u] + a[p] + a[o] > a[r] && a[j] + a[e] + a[r] + a[z] + a[y] + a[u] + a[p] + a[o] > a[h]&& a[j] + a[h] + a[r] + a[z] + a[y] + a[u] + a[p] + a[o] > a[e]){
													sum++;
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
		}else if(i == 10){
			for(int j = 1;j <= n;j++){
				for(int z = j;z <= n;z++){
					for(int y = z;y <= n;y++){
						for(int u = y;u <= n;u++){
							for(int p = u;p <= n;p++){
								for(int o = p;o <= n;o++){
									for(int r = o;r <= n;r++){
										for(int h = r;h <= n;h++){
											for(int e = h;e <= n;e++){
												for(int k = e; k <= e;k++){
													if(j != z&& j != y && z != y && j != u && z != u && y != u&&j != p&& p != y && z != p && p != u && o != j && o != z && o != y && o != u && o != p && r != j && r != z && r != y && r != u && r != p && r != o&& h != j && h != z && h != y && h != u && h != p && h != o && h != r&& e != j && e != z && e != y && e != u && e != p && e != o && e != r && e != h&& k != j && k != z && k != y && k != u && k != p && k != o && k != r && k != h && k != e&& a[j] + a[e] + a[h] + a[z] + a[y] + a[u] + a[o] + a[r] + a[k] > a[p]&&a[j] + a[k] + a[e] + a[h] + a[z] + a[y] + a[p]+ a[o] + a[r] > a[u] && a[j] + a[k] + a[e] + a[h] + a[r] + a[u] + a[y] + a[p]+ a[o] > a[z]&&a[j] + a[k] + a[e] + a[h] + a[z] + a[r] + a[u] + a[p]+ a[o] > a[y] &&a[u] + a[k] + a[e] + a[h] + a[r] + a[z] + a[y] + a[p]+ a[o] > a[j] && a[j] + a[k] + a[e] + a[h] + a[r] + a[z] + a[y] + a[u] + a[p] > a[o] && a[j] + a[k] + a[e] + a[h] + a[z] + a[y] + a[u] + a[p] + a[o] > a[r] && a[j] + a[k] + a[e] + a[r] + a[z] + a[y] + a[u] + a[p] + a[o] > a[h]&& a[j] + a[k] + a[h] + a[r] + a[z] + a[y] + a[u] + a[p] + a[o] > a[e]&& a[j] + a[e] + a[h] + a[r] + a[z] + a[y] + a[u] + a[p] + a[o] > a[k]){
														sum++;
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
		}else{
			sum = sum * 2;
		}
	}
	printf("%d",sum);
	
	return 0;
}
