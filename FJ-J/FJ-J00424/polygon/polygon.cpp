#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,u[105] = {},ans = 0;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> u[i];
	}
	if(n == 3){
		for(int i = 0;i+1 < n;i++){
			for(int j = i+1;j < n;j++){
				for(int c = j+1;c < n;c++){
					if(2 * max(u[i],max(u[j],u[c])) < u[i]+u[j]+u[c]){
						ans++;
					}
				}
			}
		}
	}
	else if(n == 4){
		for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				for(int c = j+1;c < n;c++){
					for(int v = c+1;v < n;v++){
						if(2 * max(u[i],max(u[j],max(u[c],u[v]))) < u[i]+u[j]+u[c]+u[v]){
							ans++;
						}
					}
					
				}
			}
		}
		for(int i = 0;i+1 < n;i++){
			for(int j = i+1;j < n;j++){
				for(int c = j+1;c < n;c++){
					if(2 * max(u[i],max(u[j],u[c])) < u[i]+u[j]+u[c]){
						ans++;
					}
				}
			}
		}
	}else if(n == 5){
		for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				for(int c = j+1;c < n;c++){
					for(int v = c+1;v < n;v++){
						for(int y = v+1;y < n;y++){
							if(2 * max(u[i],max(u[j],max(u[c],max(u[y],u[v])))) < u[i]+u[j]+u[c]+u[v]+u[y]){
								ans++;
							}
						}
						
					}
					
				}
			}
		}
		for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				for(int c = j+1;c < n;c++){
					for(int v = c+1;v < n;v++){
						if(2 * max(u[i],max(u[j],max(u[c],u[v]))) < u[i]+u[j]+u[c]+u[v]){
							ans++;
						}
					}
					
				}
			}
		}
		for(int i = 0;i+1 < n;i++){
			for(int j = i+1;j < n;j++){
				for(int c = j+1;c < n;c++){
					if(2 * max(u[i],max(u[j],u[c])) < u[i]+u[j]+u[c]){
						ans++;
					}
				}
			}
		}
	}else if(n == 6){
		for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				for(int c = j+1;c < n;c++){
					for(int v = c+1;v < n;v++){
						for(int y = v+1;y < n;y++){
							for(int q = y+1;q < n;q++){
								if(2 * max(u[i],max(u[j],max(u[c],max(u[y],max(u[v],u[q]))))) < u[i]+u[j]+u[c]+u[v]+u[y]+u[q]){
								ans++;
							}
							}
							
						}
						
					}
					
				}
			}
		}
		for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				for(int c = j+1;c < n;c++){
					for(int v = c+1;v < n;v++){
						for(int y = v+1;y < n;y++){
							if(2 * max(u[i],max(u[j],max(u[c],max(u[y],u[v])))) < u[i]+u[j]+u[c]+u[v]+u[y]){
								ans++;
							}
						}
						
					}
					
				}
			}
		}
		for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				for(int c = j+1;c < n;c++){
					for(int v = c+1;v < n;v++){
						if(2 * max(u[i],max(u[j],max(u[c],u[v]))) < u[i]+u[j]+u[c]+u[v]){
							ans++;
						}
					}
					
				}
			}
		}
		for(int i = 0;i+1 < n;i++){
			for(int j = i+1;j < n;j++){
				for(int c = j+1;c < n;c++){
					if(2 * max(u[i],max(u[j],u[c])) < u[i]+u[j]+u[c]){
						ans++;
					}
				}
			}
		}
	}else if(n == 7){
		for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				for(int c = j+1;c < n;c++){
					for(int v = c+1;v < n;v++){
						for(int y = v+1;y < n;y++){
							for(int q = y+1;q < n;q++){
								for(int d= q+1;d < n;d++){
									if(2 * max(u[i],max(u[j],max(u[c],max(u[y],max(u[v],max(u[q],u[d])))))) < u[i]+u[j]+u[c]+u[v]+u[y]+u[q]+u[d]){
									ans++;
									}
								}
								
							}
							
						}
						
					}
					
				}
			}
		}
		for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				for(int c = j+1;c < n;c++){
					for(int v = c+1;v < n;v++){
						for(int y = v+1;y < n;y++){
							for(int q = y+1;q < n;q++){
								if(2 * max(u[i],max(u[j],max(u[c],max(u[y],max(u[v],u[q]))))) < u[i]+u[j]+u[c]+u[v]+u[y]+u[q]){
								ans++;
							}
							}
							
						}
						
					}
					
				}
			}
		}
		for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				for(int c = j+1;c < n;c++){
					for(int v = c+1;v < n;v++){
						for(int y = v+1;y < n;y++){
							if(2 * max(u[i],max(u[j],max(u[c],max(u[y],u[v])))) < u[i]+u[j]+u[c]+u[v]+u[y]){
								ans++;
							}
						}
						
					}
					
				}
			}
		}
		for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				for(int c = j+1;c < n;c++){
					for(int v = c+1;v < n;v++){
						if(2 * max(u[i],max(u[j],max(u[c],u[v]))) < u[i]+u[j]+u[c]+u[v]){
							ans++;
						}
					}
					
				}
			}
		}
		for(int i = 0;i+1 < n;i++){
			for(int j = i+1;j < n;j++){
				for(int c = j+1;c < n;c++){
					if(2 * max(u[i],max(u[j],u[c])) < u[i]+u[j]+u[c]){
						ans++;
					}
				}
			}
		}
	}else if(n == 8){
		for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				for(int c = j+1;c < n;c++){
					for(int v = c+1;v < n;v++){
						for(int y = v+1;y < n;y++){
							for(int q = y+1;q < n;q++){
								for(int d= q+1;d < n;d++){
									for(int p = d+1;p < n;p++)
									if(2 * max(u[i],max(u[j],max(u[c],max(u[y],max(u[v],max(u[q],max(u[d],u[p]))))))) < u[i]+u[j]+u[c]+u[v]+u[y]+u[q]+u[d]+u[p]){
										ans++;
									}
								}
								
							}
							
						}
						
					}
					
				}
			}
		}
		for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				for(int c = j+1;c < n;c++){
					for(int v = c+1;v < n;v++){
						for(int y = v+1;y < n;y++){
							for(int q = y+1;q < n;q++){
								for(int d= q+1;d < n;d++){
									if(2 * max(u[i],max(u[j],max(u[c],max(u[y],max(u[v],max(u[q],u[d])))))) < u[i]+u[j]+u[c]+u[v]+u[y]+u[q]+u[d]){
									ans++;
									}
								}
								
							}
							
						}
						
					}
					
				}
			}
		}
		for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				for(int c = j+1;c < n;c++){
					for(int v = c+1;v < n;v++){
						for(int y = v+1;y < n;y++){
							for(int q = y+1;q < n;q++){
								if(2 * max(u[i],max(u[j],max(u[c],max(u[y],max(u[v],u[q]))))) < u[i]+u[j]+u[c]+u[v]+u[y]+u[q]){
								ans++;
							}
							}
							
						}
						
					}
					
				}
			}
		}
		for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				for(int c = j+1;c < n;c++){
					for(int v = c+1;v < n;v++){
						for(int y = v+1;y < n;y++){
							if(2 * max(u[i],max(u[j],max(u[c],max(u[y],u[v])))) < u[i]+u[j]+u[c]+u[v]+u[y]){
								ans++;
							}
						}
						
					}
					
				}
			}
		}
		for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				for(int c = j+1;c < n;c++){
					for(int v = c+1;v < n;v++){
						if(2 * max(u[i],max(u[j],max(u[c],u[v]))) < u[i]+u[j]+u[c]+u[v]){
							ans++;
						}
					}
					
				}
			}
		}
		for(int i = 0;i+1 < n;i++){
			for(int j = i+1;j < n;j++){
				for(int c = j+1;c < n;c++){
					if(2 * max(u[i],max(u[j],u[c])) < u[i]+u[j]+u[c]){
						ans++;
					}
				}
			}
		}
	}else if(n == 9){
				for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				for(int c = j+1;c < n;c++){
					for(int v = c+1;v < n;v++){
						for(int y = v+1;y < n;y++){
							for(int q = y+1;q < n;q++){
								for(int d= q+1;d < n;d++){
									for(int p = d+1;p < n;p++){ 
										for(int f = p+1;f < n;f++){
											if(2 * max(u[i],max(u[j],max(u[c],max(u[y],max(u[v],max(u[q],max(u[d],max(u[f],u[p])))))))) < u[i]+u[j]+u[c]+u[v]+u[y]+u[q]+u[d]+u[p]+u[f]){
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
		for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				for(int c = j+1;c < n;c++){
					for(int v = c+1;v < n;v++){
						for(int y = v+1;y < n;y++){
							for(int q = y+1;q < n;q++){
								for(int d= q+1;d < n;d++){
									for(int p = d+1;p < n;p++)
									if(2 * max(u[i],max(u[j],max(u[c],max(u[y],max(u[v],max(u[q],max(u[d],u[p]))))))) < u[i]+u[j]+u[c]+u[v]+u[y]+u[q]+u[d]+u[p]){
										ans++;
									}
								}
								
							}
							
						}
						
					}
					
				}
			}
		}
		for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				for(int c = j+1;c < n;c++){
					for(int v = c+1;v < n;v++){
						for(int y = v+1;y < n;y++){
							for(int q = y+1;q < n;q++){
								for(int d= q+1;d < n;d++){
									if(2 * max(u[i],max(u[j],max(u[c],max(u[y],max(u[v],max(u[q],u[d])))))) < u[i]+u[j]+u[c]+u[v]+u[y]+u[q]+u[d]){
									ans++;
									}
								}
								
							}
							
						}
						
					}
					
				}
			}
		}
		for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				for(int c = j+1;c < n;c++){
					for(int v = c+1;v < n;v++){
						for(int y = v+1;y < n;y++){
							for(int q = y+1;q < n;q++){
								if(2 * max(u[i],max(u[j],max(u[c],max(u[y],max(u[v],u[q]))))) < u[i]+u[j]+u[c]+u[v]+u[y]+u[q]){
								ans++;
							}
							}
							
						}
						
					}
					
				}
			}
		}
		for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				for(int c = j+1;c < n;c++){
					for(int v = c+1;v < n;v++){
						for(int y = v+1;y < n;y++){
							if(2 * max(u[i],max(u[j],max(u[c],max(u[y],u[v])))) < u[i]+u[j]+u[c]+u[v]+u[y]){
								ans++;
							}
						}
						
					}
					
				}
			}
		}
		for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				for(int c = j+1;c < n;c++){
					for(int v = c+1;v < n;v++){
						if(2 * max(u[i],max(u[j],max(u[c],u[v]))) < u[i]+u[j]+u[c]+u[v]){
							ans++;
						}
					}
					
				}
			}
		}
		for(int i = 0;i+1 < n;i++){
			for(int j = i+1;j < n;j++){
				for(int c = j+1;c < n;c++){
					if(2 * max(u[i],max(u[j],u[c])) < u[i]+u[j]+u[c]){
						ans++;
					}
				}
			}
		}
	}else{
			for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				for(int c = j+1;c < n;c++){
					for(int v = c+1;v < n;v++){
						for(int y = v+1;y < n;y++){
							for(int q = y+1;q < n;q++){
								for(int d= q+1;d < n;d++){
									for(int p = d+1;p < n;p++){ 
										for(int f = p+1;f < n;f++){
											for(int r = f+1;r < n;r++){
												if(2 * max(u[i],max(u[j],max(u[c],max(u[y],max(u[v],max(u[q],max(u[d],max(u[f],max(u[r],u[p]))))))))) < u[i]+u[j]+u[c]+u[v]+u[y]+u[q]+u[d]+u[p]+u[f]){
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
				for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				for(int c = j+1;c < n;c++){
					for(int v = c+1;v < n;v++){
						for(int y = v+1;y < n;y++){
							for(int q = y+1;q < n;q++){
								for(int d= q+1;d < n;d++){
									for(int p = d+1;p < n;p++){ 
										for(int f = p+1;f < n;f++){
											if(2 * max(u[i],max(u[j],max(u[c],max(u[y],max(u[v],max(u[q],max(u[d],max(u[f],u[p])))))))) < u[i]+u[j]+u[c]+u[v]+u[y]+u[q]+u[d]+u[p]+u[f]){
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
		for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				for(int c = j+1;c < n;c++){
					for(int v = c+1;v < n;v++){
						for(int y = v+1;y < n;y++){
							for(int q = y+1;q < n;q++){
								for(int d= q+1;d < n;d++){
									for(int p = d+1;p < n;p++)
									if(2 * max(u[i],max(u[j],max(u[c],max(u[y],max(u[v],max(u[q],max(u[d],u[p]))))))) < u[i]+u[j]+u[c]+u[v]+u[y]+u[q]+u[d]+u[p]){
										ans++;
									}
								}
								
							}
							
						}
						
					}
					
				}
			}
		}
		for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				for(int c = j+1;c < n;c++){
					for(int v = c+1;v < n;v++){
						for(int y = v+1;y < n;y++){
							for(int q = y+1;q < n;q++){
								for(int d= q+1;d < n;d++){
									if(2 * max(u[i],max(u[j],max(u[c],max(u[y],max(u[v],max(u[q],u[d])))))) < u[i]+u[j]+u[c]+u[v]+u[y]+u[q]+u[d]){
									ans++;
									}
								}
								
							}
							
						}
						
					}
					
				}
			}
		}
		for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				for(int c = j+1;c < n;c++){
					for(int v = c+1;v < n;v++){
						for(int y = v+1;y < n;y++){
							for(int q = y+1;q < n;q++){
								if(2 * max(u[i],max(u[j],max(u[c],max(u[y],max(u[v],u[q]))))) < u[i]+u[j]+u[c]+u[v]+u[y]+u[q]){
								ans++;
							}
							}
							
						}
						
					}
					
				}
			}
		}
		for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				for(int c = j+1;c < n;c++){
					for(int v = c+1;v < n;v++){
						for(int y = v+1;y < n;y++){
							if(2 * max(u[i],max(u[j],max(u[c],max(u[y],u[v])))) < u[i]+u[j]+u[c]+u[v]+u[y]){
								ans++;
							}
						}
						
					}
					
				}
			}
		}
		for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				for(int c = j+1;c < n;c++){
					for(int v = c+1;v < n;v++){
						if(2 * max(u[i],max(u[j],max(u[c],u[v]))) < u[i]+u[j]+u[c]+u[v]){
							ans++;
						}
					}
					
				}
			}
		}
		for(int i = 0;i+1 < n;i++){
			for(int j = i+1;j < n;j++){
				for(int c = j+1;c < n;c++){
					if(2 * max(u[i],max(u[j],u[c])) < u[i]+u[j]+u[c]){
						ans++;
					}
				}
			}
		}
	}
	cout << ans;
	return 0; 
}
