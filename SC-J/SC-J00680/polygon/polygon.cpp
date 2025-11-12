#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int m[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m[i];
	}
	sort(m,m+n);
	int ans=0;
	for(int x1=0;x1<n;x1++){
		for(int x2=x1+1;x2<n;x2++){
			for(int x3=x2+1;x3<n;x3++){
				if((m[x1]+m[x2]+m[x3])>(m[x3]*2)){
					ans++;
				}
			}
		}
	}
	for(int x1=0;x1<n;x1++){
		for(int x2=x1+1;x2<n;x2++){
			for(int x3=x2+1;x3<n;x3++){
				for(int x4=x3+1;x4<n;x4++){
					if((m[x1]+m[x2]+m[x3]+m[x4])>(m[x4]*2)){
						ans++;
					}
				}
			}
		}
	}
	for(int x1=0;x1<n;x1++){
		for(int x2=x1+1;x2<n;x2++){
			for(int x3=x2+1;x3<n;x3++){
				for(int x4=x3+1;x4<n;x4++){
					for(int x5=x4+1;x5<n;x5++){
						if((m[x1]+m[x2]+m[x3]+m[x4]+m[x5])>(m[x5]*2)){
							ans++;
						}
					}
				}
			}
		}
	}
	for(int x1=0;x1<n;x1++){
		for(int x2=x1+1;x2<n;x2++){
			for(int x3=x2+1;x3<n;x3++){
				for(int x4=x3+1;x4<n;x4++){
					for(int x5=x4+1;x5<n;x5++){
						for(int x6=x5+1;x6<n;x6++){
							if((m[x1]+m[x2]+m[x3]+m[x4]+m[x5]+m[x6])>(m[x6]*2)){
								ans++;
							}
						}
					}
				}
			}
		}
	}
	for(int x1=0;x1<n;x1++){
		for(int x2=x1+1;x2<n;x2++){
			for(int x3=x2+1;x3<n;x3++){
				for(int x4=x3+1;x4<n;x4++){
					for(int x5=x4+1;x5<n;x5++){
						for(int x6=x5+1;x6<n;x6++){
							for(int x7=x6+1;x7<n;x7++){
								if((m[x1]+m[x2]+m[x3]+m[x4]+m[x5]+m[x6]+m[x7])>(m[x7]*2)){
									ans++;
								}
							}
						}
					}
				}
			}
		}
	}
	for(int x1=0;x1<n;x1++){
		for(int x2=x1+1;x2<n;x2++){
			for(int x3=x2+1;x3<n;x3++){
				for(int x4=x3+1;x4<n;x4++){
					for(int x5=x4+1;x5<n;x5++){
						for(int x6=x5+1;x6<n;x6++){
							for(int x7=x6+1;x7<n;x7++){
								for(int x8=x7+1;x8<n;x8++){
									if((m[x1]+m[x2]+m[x3]+m[x4]+m[x5]+m[x6]+m[x7]+m[x8])>(m[x8]*2)){
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
	for(int x1=0;x1<n;x1++){
		for(int x2=x1+1;x2<n;x2++){
			for(int x3=x2+1;x3<n;x3++){
				for(int x4=x3+1;x4<n;x4++){
					for(int x5=x4+1;x5<n;x5++){
						for(int x6=x5+1;x6<n;x6++){
							for(int x7=x6+1;x7<n;x7++){
								for(int x8=x7+1;x8<n;x8++){
									for(int x9=x8+1;x9<n;x9++){
										if((m[x1]+m[x2]+m[x3]+m[x4]+m[x5]+m[x6]+m[x7]+m[x8]+m[x9])>(m[x9]*2)){
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
	for(int x1=0;x1<n;x1++){
		for(int x2=x1+1;x2<n;x2++){
			for(int x3=x2+1;x3<n;x3++){
				for(int x4=x3+1;x4<n;x4++){
					for(int x5=x4+1;x5<n;x5++){
						for(int x6=x5+1;x6<n;x6++){
							for(int x7=x6+1;x7<n;x7++){
								for(int x8=x7+1;x8<n;x8++){
									for(int x9=x8+1;x9<n;x9++){
										for(int x10=x9+1;x10<n;x10++){
											if((m[x1]+m[x2]+m[x3]+m[x4]+m[x5]+m[x6]+m[x7]+m[x8]+m[x9]+m[x10])>(m[x10]*2)){
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
	for(int x1=0;x1<n;x1++){
		for(int x2=x1+1;x2<n;x2++){
			for(int x3=x2+1;x3<n;x3++){
				for(int x4=x3+1;x4<n;x4++){
					for(int x5=x4+1;x5<n;x5++){
						for(int x6=x5+1;x6<n;x6++){
							for(int x7=x6+1;x7<n;x7++){
								for(int x8=x7+1;x8<n;x8++){
									for(int x9=x8+1;x9<n;x9++){
										for(int x10=x9+1;x10<n;x10++){
											for(int x11=x10+1;x11<n;x11++){
												if((m[x1]+m[x2]+m[x3]+m[x4]+m[x5]+m[x6]+m[x7]+m[x8]+m[x9]+m[x10]+m[x11])>(m[x11]*2)){
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
	}
	for(int x1=0;x1<n;x1++){
		for(int x2=x1+1;x2<n;x2++){
			for(int x3=x2+1;x3<n;x3++){
				for(int x4=x3+1;x4<n;x4++){
					for(int x5=x4+1;x5<n;x5++){
						for(int x6=x5+1;x6<n;x6++){
							for(int x7=x6+1;x7<n;x7++){
								for(int x8=x7+1;x8<n;x8++){
									for(int x9=x8+1;x9<n;x9++){
										for(int x10=x9+1;x10<n;x10++){
											for(int x11=x10+1;x11<n;x11++){
												for(int x12=x11+1;x12<n;x12++){
													if((m[x1]+m[x2]+m[x3]+m[x4]+m[x5]+m[x6]+m[x7]+m[x8]+m[x9]+m[x10]+m[x11]+m[x12])>(m[x12]*2)){
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
		}
	}
	for(int x1=0;x1<n;x1++){
		for(int x2=x1+1;x2<n;x2++){
			for(int x3=x2+1;x3<n;x3++){
				for(int x4=x3+1;x4<n;x4++){
					for(int x5=x4+1;x5<n;x5++){
						for(int x6=x5+1;x6<n;x6++){
							for(int x7=x6+1;x7<n;x7++){
								for(int x8=x7+1;x8<n;x8++){
									for(int x9=x8+1;x9<n;x9++){
										for(int x10=x9+1;x10<n;x10++){
											for(int x11=x10+1;x11<n;x11++){
												for(int x12=x11+1;x12<n;x12++){
													for(int x13=x12+1;x13<n;x13++){
														if((m[x1]+m[x2]+m[x3]+m[x4]+m[x5]+m[x6]+m[x7]+m[x8]+m[x9]+m[x10]+m[x11]+m[x12]+m[x13])>(m[x13]*2)){
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
			}
		}
	}
	for(int x1=0;x1<n;x1++){
		for(int x2=x1+1;x2<n;x2++){
			for(int x3=x2+1;x3<n;x3++){
				for(int x4=x3+1;x4<n;x4++){
					for(int x5=x4+1;x5<n;x5++){
						for(int x6=x5+1;x6<n;x6++){
							for(int x7=x6+1;x7<n;x7++){
								for(int x8=x7+1;x8<n;x8++){
									for(int x9=x8+1;x9<n;x9++){
										for(int x10=x9+1;x10<n;x10++){
											for(int x11=x10+1;x11<n;x11++){
												for(int x12=x11+1;x12<n;x12++){
													for(int x13=x12+1;x13<n;x13++){
														for(int x14=x13+1;x14<n;x14++){
															if((m[x1]+m[x2]+m[x3]+m[x4]+m[x5]+m[x6]+m[x7]+m[x8]+m[x9]+m[x10]+m[x11]+m[x12]+m[x13]+m[x14])>(m[x14]*2)){
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
				}
			}
		}
	}
	for(int x1=0;x1<n;x1++){
		for(int x2=x1+1;x2<n;x2++){
			for(int x3=x2+1;x3<n;x3++){
				for(int x4=x3+1;x4<n;x4++){
					for(int x5=x4+1;x5<n;x5++){
						for(int x6=x5+1;x6<n;x6++){
							for(int x7=x6+1;x7<n;x7++){
								for(int x8=x7+1;x8<n;x8++){
									for(int x9=x8+1;x9<n;x9++){
										for(int x10=x9+1;x10<n;x10++){
											for(int x11=x10+1;x11<n;x11++){
												for(int x12=x11+1;x12<n;x12++){
													for(int x13=x12+1;x13<n;x13++){
														for(int x14=x13+1;x14<n;x14++){
															for(int x15=x14+1;x15<n;x15++){
																if((m[x1]+m[x2]+m[x3]+m[x4]+m[x5]+m[x6]+m[x7]+m[x8]+m[x9]+m[x10]+m[x11]+m[x12]+m[x13]+m[x14]+m[x15])>(m[x15]*2)){
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
					}
				}
			}
		}
	}
	for(int x1=0;x1<n;x1++){
		for(int x2=x1+1;x2<n;x2++){
			for(int x3=x2+1;x3<n;x3++){
				for(int x4=x3+1;x4<n;x4++){
					for(int x5=x4+1;x5<n;x5++){
						for(int x6=x5+1;x6<n;x6++){
							for(int x7=x6+1;x7<n;x7++){
								for(int x8=x7+1;x8<n;x8++){
									for(int x9=x8+1;x9<n;x9++){
										for(int x10=x9+1;x10<n;x10++){
											for(int x11=x10+1;x11<n;x11++){
												for(int x12=x11+1;x12<n;x12++){
													for(int x13=x12+1;x13<n;x13++){
														for(int x14=x13+1;x14<n;x14++){
															for(int x15=x14+1;x15<n;x15++){
																for(int x16=x15+1;x16<n;x16++){
																	if((m[x1]+m[x2]+m[x3]+m[x4]+m[x5]+m[x6]+m[x7]+m[x8]+m[x9]+m[x10]+m[x11]+m[x12]+m[x13]+m[x14]+m[x15]+m[x16])>(m[x16]*2)){
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
						}
					}
				}
			}
		}
	}
	for(int x1=0;x1<n;x1++){
		for(int x2=x1+1;x2<n;x2++){
			for(int x3=x2+1;x3<n;x3++){
				for(int x4=x3+1;x4<n;x4++){
					for(int x5=x4+1;x5<n;x5++){
						for(int x6=x5+1;x6<n;x6++){
							for(int x7=x6+1;x7<n;x7++){
								for(int x8=x7+1;x8<n;x8++){
									for(int x9=x8+1;x9<n;x9++){
										for(int x10=x9+1;x10<n;x10++){
											for(int x11=x10+1;x11<n;x11++){
												for(int x12=x11+1;x12<n;x12++){
													for(int x13=x12+1;x13<n;x13++){
														for(int x14=x13+1;x14<n;x14++){
															for(int x15=x14+1;x15<n;x15++){
																for(int x16=x15+1;x16<n;x16++){
																	for(int x17=x16+1;x17<n;x17++){
																		if((m[x1]+m[x2]+m[x3]+m[x4]+m[x5]+m[x6]+m[x7]+m[x8]+m[x9]+m[x10]+m[x11]+m[x12]+m[x13]+m[x14]+m[x15]+m[x16]+m[x17])>(m[x17]*2)){
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
							}
						}
					}
				}
			}
		}
	}
	for(int x1=0;x1<n;x1++){
		for(int x2=x1+1;x2<n;x2++){
			for(int x3=x2+1;x3<n;x3++){
				for(int x4=x3+1;x4<n;x4++){
					for(int x5=x4+1;x5<n;x5++){
						for(int x6=x5+1;x6<n;x6++){
							for(int x7=x6+1;x7<n;x7++){
								for(int x8=x7+1;x8<n;x8++){
									for(int x9=x8+1;x9<n;x9++){
										for(int x10=x9+1;x10<n;x10++){
											for(int x11=x10+1;x11<n;x11++){
												for(int x12=x11+1;x12<n;x12++){
													for(int x13=x12+1;x13<n;x13++){
														for(int x14=x13+1;x14<n;x14++){
															for(int x15=x14+1;x15<n;x15++){
																for(int x16=x15+1;x16<n;x16++){
																	for(int x17=x16+1;x17<n;x17++){
																		for(int x18=x17+1;x18<n;x18++){
																			if((m[x1]+m[x2]+m[x3]+m[x4]+m[x5]+m[x6]+m[x7]+m[x8]+m[x9]+m[x10]+m[x11]+m[x12]+m[x13]+m[x14]+m[x15]+m[x16]+m[x17]+m[x18])>(m[x18]*2)){
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
								}
							}
						}
					}
				}
			}
		}
	}
	for(int x1=0;x1<n;x1++){
		for(int x2=x1+1;x2<n;x2++){
			for(int x3=x2+1;x3<n;x3++){
				for(int x4=x3+1;x4<n;x4++){
					for(int x5=x4+1;x5<n;x5++){
						for(int x6=x5+1;x6<n;x6++){
							for(int x7=x6+1;x7<n;x7++){
								for(int x8=x7+1;x8<n;x8++){
									for(int x9=x8+1;x9<n;x9++){
										for(int x10=x9+1;x10<n;x10++){
											for(int x11=x10+1;x11<n;x11++){
												for(int x12=x11+1;x12<n;x12++){
													for(int x13=x12+1;x13<n;x13++){
														for(int x14=x13+1;x14<n;x14++){
															for(int x15=x14+1;x15<n;x15++){
																for(int x16=x15+1;x16<n;x16++){
																	for(int x17=x16+1;x17<n;x17++){
																		for(int x18=x17+1;x18<n;x18++){
																			for(int x19=x18+1;x19<n;x19++){
																				if((m[x1]+m[x2]+m[x3]+m[x4]+m[x5]+m[x6]+m[x7]+m[x8]+m[x9]+m[x10]+m[x11]+m[x12]+m[x13]+m[x14]+m[x15]+m[x16]+m[x17]+m[x18]+m[x19])>(m[x19]*2)){
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
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for(int x1=0;x1<n;x1++){
		for(int x2=x1+1;x2<n;x2++){
			for(int x3=x2+1;x3<n;x3++){
				for(int x4=x3+1;x4<n;x4++){
					for(int x5=x4+1;x5<n;x5++){
						for(int x6=x5+1;x6<n;x6++){
							for(int x7=x6+1;x7<n;x7++){
								for(int x8=x7+1;x8<n;x8++){
									for(int x9=x8+1;x9<n;x9++){
										for(int x10=x9+1;x10<n;x10++){
											for(int x11=x10+1;x11<n;x11++){
												for(int x12=x11+1;x12<n;x12++){
													for(int x13=x12+1;x13<n;x13++){
														for(int x14=x13+1;x14<n;x14++){
															for(int x15=x14+1;x15<n;x15++){
																for(int x16=x15+1;x16<n;x16++){
																	for(int x17=x16+1;x17<n;x17++){
																		for(int x18=x17+1;x18<n;x18++){
																			for(int x19=x18+1;x19<n;x19++){
																				for(int x20=x19+1;x20<n;x20++){
																					if((m[x1]+m[x2]+m[x3]+m[x4]+m[x5]+m[x6]+m[x7]+m[x8]+m[x9]+m[x10]+m[x11]+m[x12]+m[x13]+m[x14]+m[x15]+m[x16]+m[x17]+m[x18]+m[x19]+m[x20])>(m[x20]*2)){
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
	cout<<ans;
	return 0;
}